#include "Code.h"
#include "direct.h"
#include "Parser.h"
#include "share.h"
#include "IntFunc.h"

//#include <windows.h>

TCode::TCode() {
	CG_LOG_BEGIN

	name = nullptr;
	root = new TUnitNode(this);
}

TCode::~TCode() {
	if (name)
		delete name;
	delete root;
	
	CG_LOG_END
}

int TCode::parseUnit(id_element e, const char *unit) {
	CG_LOG_BEGIN

	name = new char[strlen(unit) + 1];
	strcpy(name, unit);

	int ret;
	*(void**)codePath = e;
	cgt->GetParam(PARAM_CODE_PATH, codePath);
	std::string fileName("hi");
	fileName.append(unit);
	CG_LOG_INFO(fileName.c_str())

	TParser *parser = new TParser();
	parser->createCodeTree(root, codePath, fileName.c_str());
#ifdef DUMP_CODE_TREE
	dump();
#endif
	if ((ret = parser->errCode)) {
		char *buf = new char[32];
		int_to_str(parser->errCode, buf);
		std::string err;
		err.append("Parser error: ").append(buf).append(" in module ").append(fileName);
		cgt->trace(err.c_str());
		dump();
		delete buf;
	}
	delete parser;

	CG_LOG_RETURN(ret)
}

TValue* TCode::run(id_element e, const char *entry, TArgs *args) {
	CG_LOG_BEGIN

	Context c(e, entry, args);
	TValue  *ret = root->run(c);

	CG_LOG_RETURN(ret)
}

void TCode::dump() {
	CG_LOG_BEGIN

	std::string s(codePath);
	HANDLE f = fopen(s.append("log").append(PATH_SLASH).append(name).append(".log").c_str(), "w+");
	root->dump(f, 0);
	fclose(f);
	
	CG_LOG_END
}
