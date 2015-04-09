#ifndef P2P_LINKLIST_H
#define P2P_LINKLIST_H

#include "tools.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ define ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//
#define		LINKLIST_PUSHBACK_DECLARE(TYPE) \
	int P2P_LL_pushback_##TYPE( LLData_s *linklist, TYPE##_s *in_data ); 

//
#define		LINKLIST_PUSHBACK_FUNCTION(TYPE) \
	int	P2P_LL_pushback_##TYPE( LLData_s *linklist, TYPE##_s *in_data ) \
	{ \
		int	err; \
		TYPE##_s *data = NULL; \
		if( linklist->type != LL_TYPE_##TYPE ) \
		{ \
			ALARM_LOG("Linklist push type error.") \
			return	P2P_ERROR; \
		} \
		data = (TYPE##_s*)P2P_malloc( sizeof(TYPE##_s) ); \
		if( data == NULL ) \
		{ \
			ALARM_LOG("Linklist push malloc fail.") \
			return P2P_ERROR; \
		} \
		memcpy( data, in_data, sizeof(TYPE##_s) ); \
		err = P2P_LL_pushback_data(linklist,(void*)data); \
		return	err; \
	}

//
#define		LINKLIST_PUSHFRONT_DECLARE(TYPE) \
	int P2P_LL_pushfront_##TYPE( LLData_s *linklist, TYPE##_s *in_data ); 

//
#define		LINKLIST_PUSHFRONT_FUNCTION(TYPE) \
	int	P2P_LL_pushfront_##TYPE( LLData_s *linklist, TYPE##_s *in_data ) \
	{ \
		int	err; \
		TYPE##_s *data = NULL; \
		if( linklist->type != LL_TYPE_##TYPE ) \
		{ \
			ALARM_LOG("Linklist push type error.") \
			return	P2P_ERROR; \
		} \
		data = (TYPE##_s*)P2P_malloc( sizeof(TYPE##_s) ); \
		if( data == NULL ) \
		{ \
			ALARM_LOG("Linklist push malloc fail.") \
			return P2P_ERROR; \
		} \
		memcpy( data, in_data, sizeof(TYPE##_s) ); \
		err = P2P_LL_pushfront_data(linklist,(void*)data); \
		return	err; \
	}
	

//
#define		LINKLIST_GET_NODE_DECLARE(TYPE) \
	TYPE##_s*	P2P_LL_get_node_##TYPE( LLData_s *linklist );

//
#define		LINKLIST_GET_NODE_FUNCTION(TYPE) \
	TYPE##_s* P2P_LL_get_node_##TYPE( LLData_s *linklist ) \
	{ \
		if( linklist == NULL ) \
		{ \
			WARNING_LOG("linklist == NULL") \
			return NULL; \
		} \
		if( linklist->node == NULL ) \
		{ \
			WARNING_LOG("linklist->node == NULL") \
			return NULL; \
		} \
		return (TYPE##_s*)(linklist->node->data); \
	}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ enum ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

typedef enum	LL_TYPE
{
	LL_TYPE_LLTest,
} LL_TYPE_e;


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ struct ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//
typedef struct LLTest
{
	int		d1;
	int		d2;
	int		d3;
} LLTest_s;

//
typedef struct	Node
{
	struct Node	*prev;
	struct Node	*next;
	void		*data;
} Node_s;

//
typedef struct	LLData
{
	Node_s		*head;
	Node_s		*tail;
	Node_s		*node;
	LL_TYPE_e	type;
	int			size;
} LLData_s;


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ functions. ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

LLData_s*	P2P_LL_init( LL_TYPE_e type );
LLData_s*	P2P_LL_free( LLData_s *linklist );


void	P2P_LL_set_node_to_head( LLData_s *linklist );
void	P2P_LL_set_node_to_tail( LLData_s *linklist );
void	P2P_LL_move_to_next( LLData_s *linklist );
void	P2P_LL_move_to_prev( LLData_s *linklist );
int		P2P_LL_size( LLData_s *linklist );
void	P2P_LL_remove_node( LLData_s *linklist );
bool	P2P_LL_is_empty( LLData_s *linklist );
void	P2P_LL_clear( LLData_s *linklist );


LINKLIST_PUSHBACK_DECLARE(LLTest)

LINKLIST_GET_NODE_DECLARE(LLTest)




#endif