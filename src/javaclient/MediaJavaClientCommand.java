package ser321.jsonrpc;

import java.io.*;
import java.util.*;
import java.net.URL;
import org.json.JSONObject;
import org.json.JSONArray;

/**
 * Copyright (c) 2015 Tim Lindquist,
 * Software Engineering,
 * Arizona State University at the Polytechnic campus
 * <p/>
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation version 2
 * of the License.
 * <p/>
 * This program is distributed in the hope that it will be useful,
 * but without any warranty or fitness for a particular purpose.
 * <p/>
 * Please review the GNU General Public License at:
 * http://www.gnu.org/licenses/gpl-2.0.html
 * see also: https://www.gnu.org/licenses/gpl-faq.html
 * so you are aware of the terms and your rights with regard to this software.
 * Or, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,USA
 * <p/>
 * Purpose:
 * A Java class and main method demonstrating an approach to calling
 * JsonRpc methods.
 *
 * This software is meant to run on Debian Wheezy Linux
 * <p/>
 * Ser321 Principles of Distributed Software Systems
 * see http://pooh.poly.asu.edu/Ser321
 * @author Tim Lindquist (Tim.Lindquist@asu.edu) CIDSE - Software Engineering,
 *                       IAFSE, ASU at the Polytechnic campus
 * @date    July, 2015
 **/
public class MediaJavaClientCommand extends Object 
{
	public String serviceURL;
	public JsonRpcRequestViaHttp server;
	public ArrayList<String> titles;
	public ArrayList<String> videoTitles;
	public ArrayList<String> musicTitles;

	public MediaJavaClientCommand (String serviceURL) 
	{

		videoTitles = new ArrayList<String>();
		titles = new ArrayList<String>();
		musicTitles = new ArrayList<String>();
		this.serviceURL = serviceURL;

		try
		{
			this.server = new JsonRpcRequestViaHttp(new URL(serviceURL));
		}
		catch (Exception ex)
		{
			System.out.println("Malformed URL "+ex.getMessage());
		}
    }
	public void clear()
	{
		videoTitles.clear();
		titles.clear();
		musicTitles.clear();
	}
	public void getVideoTitles()
	{
		JSONObject jsonObj = new JSONObject();
		jsonObj.put("id", "1");
		jsonObj.put("jsonrpc", "2.0");
		jsonObj.put("method", "getVideoTitles");
		String jsonStr = jsonObj.toString();
		String resString = "";
		try
		{
			resString = server.call(jsonStr);
	    }
		catch(Exception e)
	    {
			System.out.println(" video we goofed");
		}
		JSONObject res = new JSONObject(resString);
		JSONArray jArray = res.getJSONArray("result");
		
		for(int i = 0; i < jArray.length(); i++)
		{
			videoTitles.add(jArray.get(i).toString());
		}
		
		for(String s : this.videoTitles)
		{
			System.out.println(s);
		}
	}
	public void getTitles()
	{
		JSONObject jsonObj = new JSONObject();
		jsonObj.put("id", "2");
		jsonObj.put("jsonrpc", "2.0");
		jsonObj.put("method", "getTitles");
		String jsonStr = jsonObj.toString();
		String resString = "";

		try
		{
			resString = server.call(jsonStr);
	    }
		catch(Exception e)
	    {
			System.out.println("titles we goofed");
		}

		JSONObject res = new JSONObject(resString);
		JSONArray jArray = res.getJSONArray("result");

		for(int i = 0; i < jArray.length(); i++)
		{
			titles.add(jArray.get(i).toString());
		}
		for(String s : titles)
		{
			System.out.println(s);
		}
	}
	public void getMusicTitles()
	{
		JSONObject jsonObj = new JSONObject();
		jsonObj.put("id", "1");
		jsonObj.put("jsonrpc", "2.0");
		jsonObj.put("method", "getMusicTitles");
		String jsonStr = jsonObj.toString();
		String resString = "";

		try
		{
			resString = server.call(jsonStr);
	    }
		catch(Exception e)
	    {
			System.out.println("music we goofed");
		}

		JSONObject res = new JSONObject(resString);
		JSONArray jArray = res.getJSONArray("result");

		for(int i = 0; i < jArray.length(); i++)
		{
			musicTitles.add(jArray.get(i).toString());
		}
		for(String s : musicTitles)
		{
			System.out.println(s);
		}
	}

	public void add(JSONObject ob)
	{
		JSONObject jsonObj = new JSONObject();
        JSONArray jArray = new JSONArray();
		jArray.put(ob);
		jsonObj.put("id", "4");
		jsonObj.put("jsonrpc", "2.0");
		jsonObj.put("method", "add");
		jsonObj.put("params", jArray);
		String jsonStr = jsonObj.toString();
		String resString = "";

		try
		{
			resString = server.call(jsonStr);
	    }
		catch(Exception e)
	    {
			System.out.println("we goofed");
		}
	
	}
	public void remove(String title)//////////////////////////
	{
		JSONObject jsonObj = new JSONObject();
		JSONArray jArray = new JSONArray();
		jArray.put(title);
		jsonObj.put("id", "6");
		jsonObj.put("jsonrpc", "2.0");
		jsonObj.put("method", "remove");
		jsonObj.put("params", jArray);
		String jsonStr = jsonObj.toString();
		String resString = "";

		try
		{
			resString = server.call(jsonStr);
	    }
		catch(Exception e)
	    {
			System.out.println("we goofed");
		}
	}
	public JSONObject get(String title)
	{
		JSONObject jsonObj = new JSONObject();
        JSONArray jArray = new JSONArray();
		jArray.put(title);
		jsonObj.put("id", "4");
		jsonObj.put("jsonrpc", "2.0");
		jsonObj.put("method", "get");
		jsonObj.put("params", jArray);
		String jsonStr = jsonObj.toString();
		String resString = "";

		try
		{
			resString = server.call(jsonStr);
	    }
		catch(Exception e)
	    {
			System.out.println("we goofed");
		}

		JSONObject res = new JSONObject(resString);
		jArray = res.getJSONArray("result");
		res = jArray.getJSONObject(0);
		//System.out.println("exiting get");
		return res;
	}

	public String serviceInfo()
	{
		return "Service information";
	}

}

