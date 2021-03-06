#include "task.h"

#include "def/def.h"
#include "thread.h"
#include "basic/linklist.h"
#include "basic/config.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ static functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifdef _WIN32
static DWORD WINAPI		P2P_task_main( void *param );
#else
static void     P2P_task_main( void *param );
#endif


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ global variable ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static LinkList_s	*_gp_linklist;	// if modify to non-static variable, be careful thah the name will be conflict.
static P2P_mutex_t	_g_mutex;



/***********************************************************
	P2P_init_task
************************************************************/
int		P2P_task_init()
{
	_gp_linklist	=	P2P_LL_init( LL_TYPE_LLTask );
	//_g_mutex		=	P2P_create_mutex( NULL, false, "P2P_task");
	P2P_mutex_init( &_g_mutex );

	return	P2P_OK;
}


/***********************************************************
	P2P_init_task
************************************************************/
#ifdef _WIN32
static DWORD WINAPI		P2P_task_main( void *param )
#else
static void     P2P_task_main( void *param )
#endif
{
	while(true)
	{
		printf("round.\n");
		P2P_sleep(100);
	}
}



/***********************************************************
	P2P_start_task
************************************************************/
int		P2P_task_start()
{
#ifdef _WIN32
	P2P_thread_create( NULL, 0, P2P_task_main, NULL, 0, NULL );
#else
    assert(0);
    //P2P_thread_create( NULL, NULL, P2P_task_main, NULL );
#endif
    
	return	P2P_OK;
}




/***********************************************************
	P2P_free_task
************************************************************/
int		P2P_task_free()
{
	_gp_linklist	=	P2P_LL_free(_gp_linklist);
	P2P_mutex_close(&_g_mutex);
	return	P2P_OK;
}




/***********************************************************
	P2P_free_task
************************************************************/
int		P2P_task_add( int sid, TASK_TYPE_e type, int round, P2P_clock_t time_interval )
{
	LLTask_s	task_data;

	task_data.sid	=	sid;
	task_data.round	=	round;
	task_data.time_interval		=	time_interval;


	return	P2P_OK;
}
