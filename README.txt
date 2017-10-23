Image Compression Algorithm
----------------------------
*[1] Read the file and make the probability matrix:*
	- In this part we read the file and make a map to map the symbols with their probabilities. 
	- We also remove the upper row and the first left row as they are always zeros. The symbol set that comes out of this operation is {0, 1, 2, 3}. 
*[2] Transform the array to character sequence:*
	- We transform the array to a char sequence in order to make it easier for the next levels to manipulate this sequence. 
	- The symbol set that comes out of this operation is {0, 1, 2, 3}.
*[3] Adaptive Huffman encoding algorithm:* 
	- In this level we apply the adaptive Huffman encoding algorithm using a tree. 
	- We initialize the code in the tree with {0 , 1 , 2 , 3 }. 
	- The symbol set that comes out of this operation is {0 , 1}. 
*[4] Write the compressed file:* 
	- First we map each character (which is a byte in size) to the corresponding bit. 
	- The file format contains (2 bytes holds the size(N) of the code and N/8 bytes that holds the code itself. 

Image Decompression Algorithm
------------------------------
*[1] Read the file and map the bits into chars:*
	- First we read the binary compressed file. 
	- Second we map each bit which had been read from the file into a char. The symbol set that comes out of this operation is {0 , 1}. 
*[2] The Huffman decoding algorithm:*
	- In this level we apply the adaptive Huffman decoding algorithm using a tree. 
	- We initialize the code in the tree with {0 , 1 , 2 , 3 }. 
	- The symbol set that comes out of this operation is {0 , 1 ,   , 4}. 
*[3] Convert the symbols into a matrix:*
	- In this step we convert the code sequence into a matrix that can we written to a file. 
	- We add the upper row and the first left column which was removed in the encoding operation. 
*[4] Write the decoded image:*
	- In this step we just write the data to the image file. 


