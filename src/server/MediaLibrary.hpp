#ifndef MEDIA_LIBRARY_INCLUDED
#define MEDIA_LIBRARY_INCLUDED

#include<string>
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
#include<vector>
#include"MediaDescription.hpp"
#include<json/json.h>

using namespace std;

class MediaLibrary
{
private:
	vector<MediaDescription> list;

public:
	MediaLibrary();
	//default constructor
	MediaLibrary(string jsonFileName);
	//for initializing from json file
	void toJsonFile(string jsonFileName);
	//writes the library to a json file
        void initialize(string jsonFileName);
	bool add(MediaDescription aClip);
	//add a MediaDescription to the library
	bool remove(string aTitle);
	//remove the named MediaDescription from library
	Json::Value get(string aTitle);
	//returns the named MediaDescription
	Json::Value getTitles();
	//returns a vector of all titles
	Json::Value getMusicTitles();
	//returns a vector of only music titles
	Json::Value getVideoTitles();
	//returns a vector of only video titles

};
#endif
