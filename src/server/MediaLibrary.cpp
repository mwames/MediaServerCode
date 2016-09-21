/**
* Copyright 2016 Matthew Ames,
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* Purpose: demonstrate Java and C++ Ant build file.
*
* Ser321 Foundations of Distributed Applications
* see http://pooh.poly.asu.edu/Ser321
* @author Matthew Ames mwames@asu.edu
* @version January 2016
*/
#include "MediaLibrary.hpp"
#include "MediaDescription.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <json/json.h>

using namespace std;

MediaLibrary::MediaLibrary()
{
	list.clear();
	list.resize(0);
}
MediaLibrary::MediaLibrary(string jsonFileName)
{
	vector<string> myVec;
	ifstream inStream;
	inStream.open(jsonFileName);
	Json::Reader reader;
	Json::Value root;
	reader.parse(inStream, root);
	myVec = root.getMemberNames();
	Json::Value member;
	for (int i = 0; i < myVec.size(); i++)
	{
		member = root.get(myVec[i], "");
		MediaDescription md(member);
		list.push_back(md);
		cout << member.get("title", "") << " added" << endl;
	}
}
void MediaLibrary::initialize(string jsonFileName)
{
vector<string> myVec;
	ifstream inStream;
	inStream.open(jsonFileName);
	Json::Reader reader;
	Json::Value root;
	reader.parse(inStream, root);
	myVec = root.getMemberNames();
	Json::Value member;
	for (int i = 0; i < myVec.size(); i++)
	{
		member = root.get(myVec[i], "");
		MediaDescription md(member);
		list.push_back(md);
		cout << member.get("title", "") << " added" << endl;
	}
}

void MediaLibrary::toJsonFile(string jsonFileName)
{
	Json::Value root;
	for (int i = 0; i < list.size(); i++)
	{
		root[list[i].getTitle()] = list[i].toJsonValue();
	}
	Json::StyledStreamWriter ssw("");
	ofstream jsonOut(jsonFileName.c_str());
	ssw.write(jsonOut, root);
	jsonOut.close();
}
bool MediaLibrary::add(MediaDescription aClip)
{
	for(int i = 0; i < list.size(); i++)
	{
		if (aClip.getTitle().compare(list[i].getTitle()) == 0)
			return false;
	}
	list.push_back(aClip);

	for (int i = list.size()-1; i > -1; i--)//ensure clip was added to list
	{
		if (list[i].getTitle().compare(aClip.getTitle()) == 0)
			return true;
	}
	
	return false;
}

bool MediaLibrary::remove(string aTitle)
{
	bool found = false;
	for (int i = 0; i < list.size(); i++)//find specified title
	{
		if (list[i].getTitle().compare(aTitle) == 0)
		{
			list.erase(list.begin()+i);
			found = true;
		}
	}
	if (!found)
	{
		cout << "Title not found" << endl;
		return false;
	}
	else //verify the found element was successfully removed
	{
		for (int i = 0; i < list.size(); i++)//find specified title
		{
			if (list[i].getTitle().compare(aTitle) == 0)//if title is found it wasn't removed. return false.
				return false;
		}
	}
	return true;
}

Json::Value MediaLibrary::get(string aTitle)
{
	//cout << aTitle << endl;
        Json::Value temp;
	for (int i = 0; i < list.size(); i++)//find specified title
	{
		//cout << "searching for title" << endl;
		if (list[i].getTitle().compare(aTitle) == 0)
		{
			//cout << "title found" << endl;
			temp.append(list[i].toJsonValue());
			//cout << "temp size in MediaLibrary: " << temp.size() << endl;
			return temp;
		}
	}
	cout << "Title not found" << endl;
	return temp;
}

Json::Value MediaLibrary::getTitles()
{
	Json::Value temp;
	for (int i = 0; i < list.size(); i++)
	{
		temp.append(list[i].getTitle());
	}
	return temp;
}

Json::Value MediaLibrary::getMusicTitles()
{
	Json::Value temp;
	for (int i = 0; i < list.size(); i++)
	{
		if(list[i].getMediaType().compare("0") == 0)
			temp.append(list[i].getTitle());
	}
	return temp;
}

Json::Value MediaLibrary::getVideoTitles()
{
	Json::Value temp;
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i].getMediaType().compare("1") == 0)
			temp.append(list[i].getTitle());
	}
	return temp;
}
