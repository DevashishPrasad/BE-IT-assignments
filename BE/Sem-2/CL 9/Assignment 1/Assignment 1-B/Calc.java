import java.rmi.*;  

public interface Calc extends Remote{  
	public int add(int x,int y)throws RemoteException;  
	public int substract(int x,int y)throws RemoteException;  
	public int multiply1(int x,int y)throws RemoteException;  
	public int square(int x)throws RemoteException;  
	public int cube(int x)throws RemoteException;  
}  