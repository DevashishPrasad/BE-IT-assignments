import mpi.MPI;


public class mpiprogram {

	public static void main(String args[]) {
		
		//Initialize and finalize
		MPI.Init(args);           //takes a reference to the command line arguments

		int root = 0;
		//Rank and Size
		int size = MPI.COMM_WORLD.Size();   //Whenever program is ran in mpi all processes are grouped in an communicator.
		int rank = MPI.COMM_WORLD.Rank();

		if(rank == root) 
		{
			System.out.println("Size of MPI Communicator : "+size);
		}
		System.out.println("\nThis process has rank "+rank);

		// Initializing the send buffer

		int sendbuf[] = new int[size];

		if(rank == root) {

			sendbuf[0] = 10;
			sendbuf[1] = 20;
			sendbuf[2] = 30;
			sendbuf[3] = 40;

			System.out.println("Data to be scattered by process "+rank+": ");
			for(int i=0;i<size;i++)
			{

				System.out.print("\n"+sendbuf[i]+" ");
			}	
		}
		int recvbuf[] = new int[1];                                      //Declaring receive buffer
	
		//scatter (it sends chunk of array to different processes)
		
		MPI.COMM_WORLD.Scatter(sendbuf, 0, 1, MPI.INT,    //(Send buffer, Start of the data in buffer, chunk size,datatype)
					 recvbuf, 0, 1, MPI.INT,
					root);

		//double the data

		System.out.println("Process "+rank+" has data: "+recvbuf[0]);		
		recvbuf[0] = recvbuf[0]*2;
		
		//gather(it takes each process and gathers them to the root process)

		MPI.COMM_WORLD.Gather(recvbuf, 0, 1, MPI.INT,
				               sendbuf, 0, 1, MPI.INT,
				               root);

		//display the doubled data
		if(rank == root) {
			System.out.println("The root process "+rank +" has data: ");
			for(int i=0;i<size;i++)
				System.out.print(sendbuf[i]+" ");
		}

		MPI.Finalize();
	}
}