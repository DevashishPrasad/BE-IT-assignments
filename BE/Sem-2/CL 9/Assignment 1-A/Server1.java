import java.util.*;
import java.net.*;
import java.io.*;

public class Server1 {

    public static void main(String s[]) throws Exception {
        Socket sa = null;
        ServerSocket ss2 = null;
        System.out.println("server listening ");
        try {
            ss2 = new ServerSocket(4445);
        } catch (IOException e) {
            System.out.println("server error");
        }
        int i =1;
        while (true) {
            try {
                sa = ss2.accept();
                System.out.println("connetion established");
                
                ServerThread st = new ServerThread(sa,"Client "+String.valueOf(i));
                i++;
                st.start();
            } catch (Exception e) {
                System.out.println("connetion error");
            }
        }
    }
}

class ServerThread extends Thread {
    String line = null;
    DataInputStream is = null;
    PrintWriter od = null;
    Socket s1 = null;
    String clientnum = "";
    public ServerThread(Socket s, String clientnum) {
        s1 = s;
        this.clientnum= clientnum; 
    }

    public void run() {
        try {

            is = new DataInputStream(s1.getInputStream());
            od = new PrintWriter(s1.getOutputStream());
            DataInputStream din = new DataInputStream(System.in);

            line = is.readLine();

            while (!line.equals("QUIT")) {
                od.println(line);
                od.flush();
                System.out.println(clientnum+" : "+line+"\n");
                line = is.readLine();

            }
            is.close();
            od.close();
            s1.close();

        } catch (IOException ie) {
            System.out.println("socket close error");
        }
    }
}