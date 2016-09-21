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
#include "MediaDescription.hpp"
#include <json/json.h>

MediaDescription::MediaDescription()
{
	mediaType = "";
	title = "";
	author = "";
	album = "";
	genre = "";
	filename = "";
}

MediaDescription::MediaDescription(string mediaType, string title, string author, string album, string genre, string filename)
{
	this->mediaType = mediaType;
	this->title = title;
	this->author = author;
	this->album = album;
	this->genre = genre;
	this->filename = filename;
}
MediaDescription::MediaDescription(Json::Value value)
{
	if(value.get("mediaType", "").asInt() == 0)
		this->mediaType = "0";
	else
		this->mediaType = "1";	
	this->title = value.get("title", "").asString();
	this->author = value.get("author", "").asString();
	this->album = value.get("album", "").asString();
	this->genre = value.get("genre", "").asString();
	this->filename = value.get("filename", "").asString();
}
Json::Value MediaDescription::toJsonValue()
{
	Json::Value value;
	value["title"] = this->title;
	value["mediaType"] = this->mediaType;
	value["author"] = this->author;
	value["album"] = this->album;
	value["genre"] = this->genre;
	value["filename"] = this->filename;
	return value;
}
string MediaDescription::getMediaType()
{
	return this->mediaType;
}

void MediaDescription::setMediaType(string mediaType)
{
	this->mediaType = mediaType;
}

string MediaDescription::getTitle()
{
	return this->title;
}

void MediaDescription::setTitle(string title)
{
	this->title = title;
}

string MediaDescription::getAuthor()
{
	return this->author;
}

void MediaDescription::setAuthor(string author)
{
	this->author = author;
}

string MediaDescription::getAlbum()
{
	return this->album;
}

void MediaDescription::setAlbum(string album)
{
	this->album = album;
}

string MediaDescription::getGenre()
{
	return this->genre;
}

void MediaDescription::setGenre(string genre)
{
	this->genre = genre;
}

string MediaDescription::getFilename()
{
	return this->filename;
}

void MediaDescription::setFilename()
{
	this->filename = filename;
}

string MediaDescription::toString()
{
	return "filename: " + this->filename + ", author: " + this->author + ", album: " + this->album + ", genre: " + this->genre + ", mediaType: " + this->mediaType + ", title: " + this->title;
}
