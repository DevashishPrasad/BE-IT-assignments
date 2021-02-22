import java.rmi.registry.*;
import java.rmi.*;  
import java.rmi.server.*; 
import java.util.*;
public class Client{
	private Client()throws RemoteException {}
	public static void main(String[] args) {
		try{
			Calc stub=(Calc)Naming.lookup("rmi://localhost:5000/calculate");  
			Scanner sc = new Scanner(System.in);

			int a,b,choice;
			while(true){
				System.out.println("\nEnter your choice");
				System.out.println("1. Addition");
				System.out.println("2. Substraction");
				System.out.println("3. Multiply");
				System.out.println("4. Square");
				System.out.println("5. Cube");
				System.out.println("6. EXIT");
				choice= sc.nextInt();
				switch(choice)
				{
					case 1: 	System.out.println("Enter 1st number");
								a = sc.nextInt();
								System.out.println("Enter 2nd number");
								b = sc.nextInt();
								System.out.println("Addition of "+a+" and "+b+" is "+stub.add(a,b));  
								break;
					case 2: 	System.out.println("Enter 1st number");
								a = sc.nextInt();
								System.out.println("Enter 2nd number");
								b = sc.nextInt();
								System.out.println("Substration of "+a+" and "+b+" is "+stub.substract(a,b));  
								break;
					case 3: 	System.out.println("Enter 1st number");
								a = sc.nextInt();
								System.out.println("Enter 2nd number");
								b = sc.nextInt();
								System.out.println("Multiplication of "+a+" and "+b+" is "+stub.multiply1(a,b));  
								break;
					case 4: 	System.out.println("Enter a number");
								a = sc.nextInt();
								System.out.println("Square of "+a+" is "+stub.square(a));  
								break;
					case 5: 	System.out.println("Enter a number");
								a = sc.nextInt();
								System.out.println("Cube of "+a+" is "+stub.cube(a));  
								break;
					case 6: 	System.exit(0);

				}
			}
			
			
		}
		catch(Exception e){
			System.out.println(e);
		}
	}
}