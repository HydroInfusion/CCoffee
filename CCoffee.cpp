#include <iostream>
#include <string>
#include "resources/file_manager.h"
#include "resources/compiler.h"

// Copyright HydroInfusion & CaesarTheTrain

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
	// LINK
	string link(string src, string type) {
		string finalizedLink;
		if (type == "css" or type == "stylesheet") {
			finalizedLink = "<link rel=\"stylesheet\" href=\"" + src + "\">";
		} else if (type == "script" or type == "js" or type == "javascript") {
			finalizedLink = "<script src=\"" + src + "\"></script>";
		}
		headWriteData = headWriteData + finalizedLink;
		return finalizedLink;
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
		} else {
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
	// HR/DIVIDER
	string divider(string style = "") {
		string finalDivider;
		if (style == "") {
			finalDivider = "<hr />";
		} else {
			finalDivider = "<hr style=\"" + style + "\" />";
		}
		bodyWriteData = bodyWriteData + finalDivider;
		return finalDivider;
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
		} else {
			widthExists = " width=\"" + width + "\" ";
		}
		if (height == "") {
			heightExists = "";
		} else {
			heightExists = " height=\"" + height + "\" ";
		}
		if (style == "") {
			styleExists = "";
		} else {
			styleExists = " style=\"" + style + "\" ";
		}
		finalizedImg = "<img" + source + widthExists + heightExists + styleExists + alt + ">";
		bodyWriteData = bodyWriteData + finalizedImg;
		return finalizedImg;
	}
	// VIDEOS
	string video(string src, string format, string width = "", string height = "", string style = "", bool controls = 1) {
		string finalizedVid;
		string widthExists;
		string heightExists;
		string styleExists;
		string controlsExists;
		if (width == "") {
			widthExists = "";
		} else {
			widthExists = " width=\"" + width + "\" ";
		}
		if (height == "") {
			heightExists = "";
		} else {
			heightExists = " height=\"" + height + "\" ";
		}
		if (style == "") {
			styleExists = "";
		} else {
			styleExists = " style=\"" + style + "\" ";
		}
		if (controls == true) {
			controlsExists = " controls";
		} else {
			controlsExists = "";
		}
		string fixedFormat = "video/" + format;
		string finalizedMid = "<source src=\"" + src + "\" type=\"" + fixedFormat + "\">";
		string FinalizedVid = "<video" + widthExists + heightExists + styleExists + controlsExists + ">" + finalizedMid + "</video>";
		bodyWriteData = bodyWriteData + FinalizedVid;
		return finalizedVid;
	}
} maindata;

// COMPILE / BUILD
class compiler {
public:
	// COMPILER
	void compile(string filename) {
		finalHead = structuralHeadShaping(headWriteData);
		finalBody = structuralBodyShaping(bodyWriteData);
		string finalData = finalHead + finalBody;
		cout << finalData;
		compile_proj(filename, finalData);
	}
} compiler;
