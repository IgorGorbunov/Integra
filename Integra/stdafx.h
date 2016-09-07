//#ifdef _DEBUG
//#define DEBUG_NEW new(__FILE__, __LINE__)
//#else
//#define DEBUG_NEW new
//#endif
////#define new DEBUG_NEW
//#include <stdlib.h>
//#include <malloc.h>
//#include <IntSafe.h>
//#include <list>
//
//typedef struct {
//	DWORD	address;
//	DWORD	size;
//	char	file[64];
//	DWORD	line;
//} ALLOC_INFO;
//
//typedef list<ALLOC_INFO*> AllocList;
//
//AllocList *allocList;
//
//void AddTrack(DWORD addr,  DWORD asize,  const char *fname, DWORD lnum)
//{
//	ALLOC_INFO *info;
//
//	if(!allocList) {
//		allocList = new(AllocList);
//	}
//
//	info = new(ALLOC_INFO);
//	info->address = addr;
//	strncpy(info->file, fname, 63);
//	info->line = lnum;
//	info->size = asize;
//	allocList->insert(allocList->begin(), info);
//};
//
//void RemoveTrack(DWORD addr)
//{
//	AllocList::iterator i;
//
//	if(!allocList)
//		return;
//	for(i = allocList->begin(); i != allocList->end(); i++)
//	{
//		if((*i)->address == addr)
//		{
//			allocList->remove((*i));
//			break;
//		}
//	}
//};
//
//
//#ifdef _DEBUG
//inline void * __cdecl operator new(unsigned int size,
//	const char *file, int line)
//{
//	void *ptr = (void *)malloc(size);
//	AddTrack((DWORD)ptr, size, file, line);
//	return(ptr);
//};
//inline void __cdecl operator delete(void *p)
//{
//	RemoveTrack((DWORD)p);
//	free(p);
//};
//#endif
