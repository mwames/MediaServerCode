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
#ifndef MEDIA_DESCRIPTION_INCLUDED
#define MEDIA_DESCRIPTION_INCLUDED
#include<string>
#include<json/json.h>

using namespace std;

class MediaDescription
{
private:
	string mediaType;
	string title;
	string author;
	string album;
	string genre;
	string filename;

public:
	MediaDescription();
	//default constructor
	MediaDescription(string mediaType, string title, string author, string album, string genre, string filename);
	//implemented constructor
	MediaDescription(Json::Value value);
	//Initialize from a JSON Value
	Json::Value toJsonValue();
	//makes the string representation of a MediaDescription into a Json Value
	string getMediaType();
	//return media type
	void setMediaType(string mediaType);
	//set mediaType
	string getTitle();
	//return title
	void setTitle(string title);
	//set title
	string getAuthor();
	//get author
	void setAuthor(string author);
	//set author
	string getAlbum();
	//get album
	void setAlbum(string album);
	//set album
	string getGenre();
	//get genre
	void setGenre(string genre);
	//set genre
	string getFilename();
	//get filename
	void setFilename();
	//set filename
	string toString();
	//return a string representation of the MediaDescription
};

#endif
