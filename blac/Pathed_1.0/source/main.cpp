/*   Application: pathEd - Path Edit command-line win32 utility
	 by Predrag Cordas

	 ver. 1.0
*/
/*	 Copyright (C) 2007  Predrag Cordas.
	 All rights reserved.

	 This program is free software; you can redistribute it and/or modify
	 it under the terms of the GNU GNU LESSER GENERAL PUBLIC LICENSE
	 (Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>).

	 This program is distributed in the hope that it will be useful,
	 but WITHOUT ANY WARRANTY; without even the implied warranty of
	 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	 GNU General Public License for more details.

	 You should have received a copy of the GNU Lesser General Public License
	 along with this program; if not, write to the Free Software
	 Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <sstream>

#include <windows.h>
#include <winable.h>
#include <stdio.h>
#include <tchar.h>

#define BUFSIZE 2000
#define REGKEY "SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment\\"
#define READKEY "Path"
#define WRITEKEY "Path"

using namespace std;

class PathEditor {
public:
	PathEditor();
	int printPath();
	int printPathNL();
	int searchPath(char *st);
	int searchPathS(char *st);
	int add2Path(char *addStr);
	int deletePath(char *delStr);
	int replacePath(char *delStr, char *newStr);
	bool verb;
	string PathEntry;
private:
	string StringToUpper(string myString);
	char *str2char(string str);
	string readPath();
	bool writePath(string strPath);
};

PathEditor::PathEditor() {
	verb = true;
}

//handy functions:
string PathEditor::StringToUpper(string myString) {
  const int length = myString.length();
  for(int i=0; i!=length ; ++i)
  {
	myString[i] = toupper(myString[i]);
  }
  return myString;
}
char  *PathEditor::str2char(string str) {
//somewhere up here str has been defined an contains data
char *buf;
buf = (char*)GlobalAlloc(GPTR, str.size());

strcpy(buf, str.c_str());


return buf;
}
string PathEditor::readPath() {
	string  strPath;
	HKEY hKey = 0;
	TCHAR  rpath[BUFSIZE] = "";
	DWORD dwBufLen=BUFSIZE*sizeof(TCHAR);
	LONG lRet = 0;

	lRet = RegOpenKeyEx( HKEY_LOCAL_MACHINE, REGKEY, 0, KEY_QUERY_VALUE, &hKey );
	if( lRet != ERROR_SUCCESS )
	{
		cout << "Registry key-a not found in registry!";
		exit(1);
	}

	lRet = RegQueryValueEx( hKey, TEXT(READKEY), NULL, NULL, (LPBYTE) rpath, &dwBufLen);
	RegCloseKey( hKey );

	if( (lRet != ERROR_SUCCESS) || (dwBufLen > BUFSIZE*sizeof(TCHAR)) )
	{
		cout << "Registry key value not available or empty!";
		exit(1);
	}

	strPath.assign(rpath);
	return strPath;
}
bool   PathEditor::writePath(string strPath) {
	HKEY hKey = 0;
	LONG lRet = 0;
	char  izmj_path[BUFSIZE] = "";
	strcpy( izmj_path, strPath.data() );

		lRet = RegOpenKeyEx( HKEY_LOCAL_MACHINE, REGKEY, 0, KEY_SET_VALUE, &hKey );
		if( lRet != ERROR_SUCCESS )		 {
			cout << "Registry key not found in registry!";
			exit(1);
		 }
		lRet = RegSetValueEx(hKey, WRITEKEY, 0, REG_SZ, (LPBYTE)izmj_path , 1000);
		RegCloseKey( hKey );
	return true;
}

//feature functions:
int PathEditor::printPath() //Print PATH registry key value
{
	string strPath = readPath();
	PathEntry = strPath;
	if (verb) {
		cout << endl << "Content of registry PATH entry: " << endl << endl << strPath << endl << endl;
	} else {
		cout << strPath <<  endl;
	}
	return 0;
}
int PathEditor::printPathNL()  //Print PATH registry key value with \n instead of ; character
{
	string strPath = readPath();

	if (verb) {cout << endl << "Content of registry PATH entry: " << endl << endl; }

	char * rpath;
	char * pch;
	rpath = new char [strPath.size()+1];
	strcpy (rpath, strPath.c_str());
	pch = strtok (rpath,";");
	while (pch != NULL) {
		printf ("%s\n",pch);
		pch = strtok (NULL, ";");
	}
	return 0;
}
int PathEditor::searchPath(char *st)  // Search for string inside PATH registry key (case sensitive)
{
	if (verb) {cout << endl << "Content of registry PATH entry: " << endl << endl; }
	string strPath = readPath();
	char * rpath;
	char * pch;
	rpath = new char [strPath.size()+1];
	strcpy (rpath, strPath.c_str());

	int zastava = 0;

	pch = strtok (rpath,";");
	while (pch != NULL)
	{
		if (!strcmp(st,pch)){
			zastava = 1;
			if (verb) {printf ("%s   <<-----------------------------------FOUND!! \n",pch);}
			pch = strtok (NULL, ";");
		} else {
			if (verb) {printf ("%s\n",pch);}
			pch = strtok (NULL, ";");
		}
	}
	if (zastava == 1)
	{
	   if(verb) {cout << endl << "There is PATH entry: "<< st <<" in PATH registry entry." << endl;}
		return 0;
	}
	if (verb) {cout << endl << "No   '" << st << "' in PATH registry entry! " << endl << endl;}
	return 1;
}
int PathEditor::searchPathS(char *st)  // Search for string inside PATH registry key (not case sensitive)
{
/*	string ajoj, srch;
//	size_t found;

	HKEY hKey = 0;
	TCHAR  rpath[BUFSIZE] = "";
	DWORD dwBufLen=BUFSIZE*sizeof(TCHAR);
	LONG lRet = 0;
//	char  izmj_path[BUFSIZE] = "";

	lRet = RegOpenKeyEx( HKEY_LOCAL_MACHINE,"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment\\", 0, KEY_QUERY_VALUE, &hKey );
	if( lRet != ERROR_SUCCESS )
	{
		cout << "Registry key not found in registry!";
		return 1;
	}

	lRet = RegQueryValueEx( hKey, TEXT("Path"), NULL, NULL, (LPBYTE) rpath, &dwBufLen);
	RegCloseKey( hKey );

	if( (lRet != ERROR_SUCCESS) || (dwBufLen > BUFSIZE*sizeof(TCHAR)) )
	{
		cout << "Registry key value not available or empty!";
		return 1;
	}
*/
	if (verb) {cout << endl << "Content of registry PATH entry: " << endl << endl;}
	string strPath = readPath();
	char * rpath;
	char * pch;
	rpath = new char [strPath.size()+1];
	strcpy (rpath, strPath.c_str());

	string ss;

	ss.assign(st);
	ss = StringToUpper(ss);
	//cout << "-->" << ss << endl;
	char* inStr;
	inStr = str2char(ss); //.c_str();
	//cout << "-->" << a << endl;

	int zastava = 0;
	ss.clear();
	ss.append(rpath);
	ss = StringToUpper(ss);
	char* cS;
	cS = str2char(ss);

	pch = strtok (cS,";");
	while (pch != NULL)
	{
		if (!strcmp(inStr,pch)){
			zastava = 1;
			if (verb) {printf ("%s   <<-------------------------------------FOUND!! \n",pch);}
			pch = strtok (NULL, ";");
		} else {
			if (verb) {printf ("%s\n",pch);}
			pch = strtok (NULL, ";");
		}
	}
	if (zastava == 1)
	{
		if (verb) {cout << endl << "There is entry: "<< inStr <<" inside PATH registry key." << endl;}
		return 0;
	}
	if (verb) {cout << endl << "There is no '" << inStr << "' entry inside PATH registry key! " << endl << endl;}
	return 1;
}
int PathEditor::add2Path(char *addStr) // Append path entry at the end of PATH registry key
{
	string ajoj, srch, cmpStr, cmpPth;
	size_t found;
	string strPath = readPath();

	srch   = srch.assign(addStr);
	cmpPth = StringToUpper(strPath);
	cmpStr = StringToUpper(cmpStr.assign(addStr));
	found  = cmpPth.find(cmpStr);
	if (found != string::npos)	{
		if (verb) {
			cout << endl << "There already is registry PATH entry: " << ajoj.substr(found,srch.length()) << endl;
			cout << "Nothing is added.." << endl;
		}
		return 1;
	} else {
		if (verb) {
			cout << endl << "Add entry not found inside registry PATH!" << endl;
			cout << "Adding to PATH entry: " << srch << endl;
		}
		strPath.append(";"+srch);
		if (writePath(strPath)) {
			return 0;
		} else {
			return 1;
		}
	}

}
int PathEditor::deletePath(char *delStr) // Delete string from the PATH registry key
{
	string ajoj, srch, cmp1, cmp2;
	char  izmj_path[BUFSIZE] = "";

	if (verb) {cout << endl << "Content of registry PATH entry: " << endl << endl;}
	string strPath = readPath();

	char * rpath;
	char * pch;
	rpath = new char [strPath.size()+1];
	strcpy (rpath, strPath.c_str());

	int zastava = 0;

	pch = strtok (rpath,";");
	while (pch != NULL){
		if (  StringToUpper(cmp1.assign(delStr)) ==  StringToUpper(cmp1.assign(pch))  ){
			zastava = 1;
			if (verb) {printf ("%s   <<---------------------DELETED!! \n",pch);}
			pch = strtok (NULL, ";");
		} else {
			if (verb) {printf ("%s\n",pch);}
			strcat(izmj_path,";");
			strcat(izmj_path,pch);
			pch = strtok (NULL, ";");
		}
	}
	if (zastava == 1) {
		string newPath = newPath.assign(izmj_path);
		if ( writePath(newPath) ) {
			if (verb) {cout << endl << "Deleted PATH entry: "<< delStr <<" from PATH registry key." << endl;}
			return 0;
		} else {
			return 1;
		}
	}else {
		if (verb) {cout << endl << "No '" << delStr << "' in PATH registry entry! Nothing deleted..." << endl << endl;}
		return 1;
	}
}
int PathEditor::replacePath(char *delStr, char *newStr) // Replace string from the PATH registry key with new one
{
	string ajoj, srch, cmp1, cmp2;
	char  izmj_path[BUFSIZE] = "";

	string strPath = readPath();
	if (verb) {cout << endl << "Content of registry PATH entry: " << endl << endl;}

	char * rpath;
	char * pch;
	rpath = new char [strPath.size()+1];
	strcpy (rpath, strPath.c_str());

	int zastava = 0;

	pch = strtok (rpath,";");
	while (pch != NULL){
		if ( StringToUpper(cmp1.assign(delStr)) ==  StringToUpper(cmp1.assign(pch)) ){
			zastava = 1;
			if (verb) {printf ("%s   <<---------------------REPLACED!! \n",pch);}
			strcat(izmj_path,";");
			strcat(izmj_path, newStr);
			pch = strtok (NULL, ";");
		} else {
			if (verb) {printf ("%s\n",pch);}
			strcat(izmj_path,";");
			strcat(izmj_path,pch);
			pch = strtok (NULL, ";");
		}
	}
	if (zastava == 1) {
		string newPath = newPath.assign(izmj_path);
		if (writePath(newPath)) {
			if (verb) {cout << endl << "Replaced PATH entry: "<< delStr << endl <<"			   with: "<< newStr << endl <<"from PATH registry key." << endl;}
			//cout << izmj_path << endl;
			return 0;
		} else {
			return 1;
		}
	}else {
		if (verb) {cout << endl << "No   '" << delStr << "' in PATH registry entry! Nothing deleted..." << endl << endl;}
		return 1;
	}
}

bool verb = true;  // set global verbous output by default!

int showHelp() // Show help message..
{
string helpStr = "															  \n \
PathEd - PathEditor win32 command-line utility															  \n \
Copyright (C) 2007  Predrag Cordas  (Under Gnu Lesser General Public License)														   \n \
																					\n \
Usage: pathed [option] [text]													 \n \
																					\n \
options:		  -h, --help		  This help									   \n \
				  -s  SearchString			  Search for string inside PATH registry key (case sensitive)   \n \
				  -S  SearchString			  Search for string inside PATH registry key (not case sensitive)   \n \
				  -p							Print PATH registry key value   \n \
				  -P							Print PATH registry key value with \\n instead of ; character   \n \
				  -a  AppendString			  Append path entry at the end of PATH registry key	\n \
				  -d  DeleteString			  Delete string from the PATH registry key	\n \
				  -r  ReplaceString NewString   Replace path entry string with new one in the PATH registry key	\n \
\n \
				  -q							quiet mode - only output is %ERRORLEVEL% !!	\n \
\n \
Exit status (%ERRORLEVEL% variable) is 0 if done OK, 1 if error. \n \
\n \
Usage examples:	\n \
  search to see if c:\\php4 exists in system PATH in registry:  pathed -S c:\\php4 \n \
  append c:\\php5 in system PATH:							   pathed -a c:\\php5 \n \
  delete c:\\php4 from system PATH (without verbous output):	pathed -dq c:\\php4  \n \
  replace c:\\php4 with c:\\php5 (quietly):					 pathed -rq c:\\php4 c:\\php5 \n \
\n \
\n \
";

	cout << helpStr << endl;
	return 0;
}

//main body:
int main(int argc, char *argv[])
{
	int izlaz = 0;
	string ar = "";

	if (argc > 1) {
		ar = ar.assign(argv[1]);
		if ( (ar.find("q")>0) && (ar.find("q")<3) ) {verb = false;}
	}

	PathEditor pEd;
	pEd.verb = verb;

	if	   ( (argc == 2) &&  (ar.find("-")==0) && (ar.find("p")<3) ) {
		izlaz = pEd.printPath();
		return izlaz;
	} else if( (argc == 2) &&  (ar.find("-")==0) && (ar.find("P")<3) ) {
		izlaz = pEd.printPathNL();
		return izlaz;
	} else if( (argc == 3) &&  (ar.find("-")==0) && (ar.find("s")<3) ) {
		izlaz = pEd.searchPath(argv[2]);
		return izlaz;
	} else if( (argc == 3) &&  (ar.find("-")==0) && (ar.find("S")<3) ) {
		izlaz = pEd.searchPathS(argv[2]);
		return izlaz;
	} else if( (argc == 3) &&  (ar.find("-")==0) && (ar.find("a")<3) ) {
		izlaz = pEd.add2Path(argv[2]);
		return izlaz;
	} else if( (argc == 3) &&  (ar.find("-")==0) && (ar.find("d")<3) ) {
		izlaz = pEd.deletePath(argv[2]);
		return izlaz;
	} else if( (argc == 4) &&  (ar.find("-")==0) && (ar.find("r")<3) ) {
		izlaz = pEd.replacePath(argv[2], argv[3]);
		return izlaz;
	} else if( (argc == 1) || !(strcmp(argv[1], "-h")) || !(strcmp(argv[1], "--help")) || (argc > 2) )  {
		izlaz = showHelp();
		if (argc == 1) return 1;
		return izlaz;
	} else {
		izlaz = showHelp();
		return 1;
	}

}
