// Shared file between both programs
#define TEXT_SZ 2048

// Shared Memory data structure
struct shared_use_st {
	int written_by_you; // Shared flag variable
	char some_text[TEXT_SZ]; // The shared buffer 
};

