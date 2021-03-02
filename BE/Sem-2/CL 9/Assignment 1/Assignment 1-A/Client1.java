import java.util.*;
import java.net.*;
import java.io.*;

public class Client1 {

    public static void main(String s[]) throws Exception {
        Socket s1 = null;
        String line = null;
        DataInputStream br = null;
        DataInputStream is = null;
        PrintWriter os = null;
        try {
            s1 = new Socket("localhost", 4445);
            br = new DataInputStream(System.in);
            is = new DataInputStream(s1.getInputStream());
            os = new PrintWriter(s1.getOutputStream());

        } catch (IOException e) {
            System.err.print("IO Exception");

        }
        
        String res = null;
        try {
             System.out.println("Enter Message: ");
            line = br.readLine();
            while (line.compareTo("QUIT") != 0) {
                os.println(line);
                os.flush();
                res = is.readLine();
                line = br.readLine();
            }
            is.close();
            os.close();
            br.close();
            s1.close();
            System.out.println("Close connection ");
        } catch (IOException e) {
            System.out.println("Socket read error");
        }
    }
}