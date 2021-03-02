import java.rmi.*;  
import java.rmi.server.*;  
public class CalcRemote extends UnicastRemoteObject implements Calc{  
	CalcRemote()throws RemoteException{  
		super();  
	}  
	public int add(int x,int y){return x+y;}  
	public int substract(int x,int y){return x-y;}  
	public int multiply1(int x,int y){return x*y;}  
	public int square(int x){return x*x;} 
	public int cube(int x){return x*x*x;} 
}  