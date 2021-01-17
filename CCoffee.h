#pragma once
#pragma once
#include <iostream>
#include <string>
#include "file_manager.h"

using namespace std;

// BASIC VARS
string bodyWriteData;
string headWriteData;

string structuralHead;
string structuralBody;

string finalHead;
string finalBody;

// HEAD
string structuralHeadShaping(string data) {
	const string head1 = "<head>";
	const string head2 = "</head>";
	string head = head1 + data + head2;
	return head;
}

// BODY
string structuralBodyShaping(string data) {
	const string body1 = "<body>";
	const string body2 = "</body>";
	string body = body1 + data + body2;
	return body;
}

// METADATA / HEAD

class metadata {
public:
	// TITLE
	string title(string str) {
		string finalizedTitle;
		const string title1 = "<title>";
		const string title2 = "</title>";
		finalizedTitle = title1 + str + title2;
		headWriteData = headWriteData + finalizedTitle;
		return finalizedTitle;
	}
} metadata;

// DATA / BODY

class maindata {
public:
	// PARAGRAPH
	string paragraph(string str, string style = "") {
		string finalizedP;
		string p1;
		if (style == "") {
			p1 = "<p>";
		}
		else {
			p1 = "<p style=\"" + style + "\">";
		}
		string p2 = "</p>";
		finalizedP = p1 + str + p2;
		bodyWriteData = bodyWriteData + finalizedP;
		return finalizedP;
	}
	// HEADERS
	string header(string str, string Operator, string style = "") {
		string finalizedHeader;
		string h;
		string h1;
		if (style == "") {
			h = "<h" + Operator + ">";
		}
		else {
			h = "<h" + Operator + " style=\"" + style + "\">";
		}
		h1 = "</h" + Operator + ">";
		finalizedHeader = h + str + h1;
		bodyWriteData = bodyWriteData + finalizedHeader;
		return finalizedHeader;
	}
	// IMAGES
	string image(string src, string width = "", string height = "", string style = "") {
		string finalizedImg;
		string widthExists = "";
		string heightExists = "";
		string styleExists = "";
		string source = " src=\"" + src + "\" ";
		string alt = " alt=\"Image not found, or failed to load.\"";
		if (width == "") {
			widthExists == "";
		}
		else {
			widthExists = " width=\"" + width + "\" ";
		}
		if (height == "") {
			heightExists = "";
		}
		else {
			heightExists = " height=\"" + height + "\" ";
		}
		if (style == "") {
			styleExists = "";
		}
		else {
			styleExists = " style=\"" + style + "\" ";
		}
		finalizedImg = "<img" + source + widthExists + heightExists + styleExists + alt + ">";
		bodyWriteData = bodyWriteData + finalizedImg;
		return finalizedImg;
	}
} maindata;

// COMPILE / BUILD
class compiler {

public:
	// COMPILER
	void compile(string filename) {

		finalHead = structuralHeadShaping(headWriteData);
		finalBody = structuralBodyShaping(bodyWriteData);
		cout << finalHead + finalBody;
		writefile(filename, "html", finalHead + finalBody);

	}

} compiler;
