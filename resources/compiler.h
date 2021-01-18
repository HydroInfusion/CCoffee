#pragma once
#include <string>
#include <iostream>
#include "file_manager.h"

void compile_proj(string filename, string data) {
	writefile(filename, "html", data);
}
