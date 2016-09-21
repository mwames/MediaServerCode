package ser321.server;

import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.io.*;


public class mediaDownloadServer extends Thread
{
		private Socket clientSocket;
		
		public mediaDownloadServer(Socket clientSocket)
		{
			this.clientSocket = clientSocket;
		}

		public void run()
		{

			
			try
			{
				//make connections to in and out streams
				InputStream inStream = clientSocket.getInputStream();
				OutputStream outStream = clientSocket.getOutputStream();
				
				//receive filename from client
				byte receiveBuffer[] = new byte[4096];
				int res = inStream.read(receiveBuffer,0,4096);
				String clientString = new String(receiveBuffer,0,res);
				String masterString = System.getProperty("user.dir")+"/src/java/dserver/DataServer/"+clientString;
				System.out.println(masterString);
				
				//retrieve file and begin transfer
				File inFile = new File(masterString);
				FileInputStream fileIn = new FileInputStream(inFile);
				int count;
				byte[] buffer = new byte[8192];
				while ((count = fileIn.read(buffer)) > 0)
				{
					outStream.write(buffer, 0, count);
				}
				inStream.close();
				outStream.close();
				fileIn.close();
				
			}
			catch(Exception e)
			{
				System.out.println("Error occurred in method run " + e.getMessage());
				
			}
		}
	public static void main(String[] args) 
	{
		try 
		{
			ServerSocket mediaServerSocket = new ServerSocket(3030);
			while(true)
			{
				System.out.println("Download Server waiting for client connect on port 3030");
				Socket clientSocket = mediaServerSocket.accept();
				System.out.println("Client connected to Download Server");
				mediaDownloadServer mds = new mediaDownloadServer(clientSocket);
				mds.start();
			}
			
		} 
		catch (Exception e) 
		{
			System.out.println("An error has occurred" + e.getMessage());
		}

	}

}
