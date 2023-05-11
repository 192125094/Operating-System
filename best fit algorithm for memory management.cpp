
using System;

public class GFG {
	

	static void bestFit(int []blockSize, int m,	int []processSize, int n)
	{
		
		
		int []allocation = new int[n];
	
	
		for (int i = 0; i < allocation.Length; i++)
			allocation[i] = -1;
	
	
		for (int i = 0; i < n; i++)
		{
			
		
			int bestIdx = -1;
			for (int j = 0; j < m; j++)
			{
				if (blockSize[j] >= processSize[i])
				{
					if (bestIdx == -1)
						bestIdx = j;
					else if (blockSize[bestIdx]
								> blockSize[j])
						bestIdx = j;
				}
			}
	
		
			if (bestIdx != -1)
			{
				
			
				allocation[i] = bestIdx;
	
			
				blockSize[bestIdx] -= processSize[i];
			}
		}
	
		Console.WriteLine("\nProcess No.\tProcess"
							+ " Size\tBlock no.");
		for (int i = 0; i < n; i++)
		{
			Console.Write(" " + (i+1) + "\t\t"
						+ processSize[i] + "\t\t");
			
			if (allocation[i] != -1)
				Console.Write(allocation[i] + 1);
			else
				Console.Write("Not Allocated");
				
			Console.WriteLine();
		}
	}
	

	public static void Main()
	{
		int []blockSize = {100, 500, 200, 300, 600};
		int []processSize = {212, 417, 112, 426};
		int m = blockSize.Length;
		int n = processSize.Length;
		
		bestFit(blockSize, m, processSize, n);
	}
