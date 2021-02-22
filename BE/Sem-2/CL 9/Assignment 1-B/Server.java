import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.*;
public class Server extends CalcRemote {

	public Server() throws RemoteException {}

	 public static void main(String[] args) {
		try{
			Calc stub=new CalcRemote();  
			Naming.rebind("rmi://localhost:5000/calculate",stub);  
			System.err.println("Server ready");
			}
			catch(Exception e){
				System.out.println(e);
			}
	}
}