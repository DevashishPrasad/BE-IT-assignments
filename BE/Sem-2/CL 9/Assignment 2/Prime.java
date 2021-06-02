import mpi.*;
import java.util.ArrayList;

public class Prime{
    final static int numbers = 20; // End point should be N
    
    static int size, position; // Total number of size
        
    final static ArrayList<Integer> primes = new ArrayList<>();;    

    public static void main(String[] args) throws Exception {
        MPI.Init(args);
        
        position = MPI.COMM_WORLD.Rank(); // Position [0 / 1]
        size = MPI.COMM_WORLD.Size(); // size [2]
        
        int begin = position * (numbers / size);
        int end = begin + (numbers / size);
        
        ArrayList<Integer> temporaryStorage = new ArrayList<>();
        for(int i = begin; i < end; i++){
            if(isNumberPrime(i)){
                temporaryStorage.add(i);
            }
        }
       
        // Send back the length the storage currently is
        if(position > 0){
            int[] sendBuf = new int[]{temporaryStorage.size()};
            MPI.COMM_WORLD.Send(sendBuf, 0, 1, MPI.INT, 0, 1);
            System.out.println("SendBuf Completed");
            for(int i = 0; i < temporaryStorage.size(); i++){
                int[] send = new int[]{temporaryStorage.get(i)};
                MPI.COMM_WORLD.Send(send, 0, 1, MPI.INT, 0, 0);
                System.out.println("Send ["+i+"] : " + temporaryStorage.get(i));
            }
        } else {
            for(int i = 0; i < temporaryStorage.size(); i++){
                primes.add(temporaryStorage.get(i));
            }
            
            int[] recvBuf = new int[1];
            for (int src = 1; src < size; src++) {
                MPI.COMM_WORLD.Recv(recvBuf, 0, 1, MPI.INT, src, 1);
                System.out.println("recvBuf Completed");
                for (int ind = 1; ind <= recvBuf[0]; ind++) {
                    int[] recv = new int[1];
                    MPI.COMM_WORLD.Recv(recv, 0, 1, MPI.INT, src, 0);
                    System.out.println("Recv ["+ind+"] : " + recv[0]);
                    primes.add(recv[0]);
                }
            }
        }
        
        MPI.Finalize();
    }
    // checking prime or not
    public static boolean isNumberPrime(int number) {  
        if(number <= 1) return false;
        for(int i = 2; i <= Math.sqrt(number); ++i)
        {
            if(number % i == 0) return false;
        }
        
        return true;  
   }
}