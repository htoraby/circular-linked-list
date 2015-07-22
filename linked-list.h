#ifndef _CIRCULAR_LINKED_LIST_
# define _CIRCULAR_LINKED_LIST_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

  /**
   * @brief A node holds a pointer to the user-defined
   * element required to be stored, a pointer to
   * the next element in the list, and a pointer to
   * the previous element in the list.
   */
  typedef struct node_t
  {
    void*		element;
    struct node_t*	next;
    struct node_t*	prev;
  } node_t;
  
  /**
   * @brief Definition of the doubly linked-list.
   * It holds informations about the current size
   * of the list, a pointer to the head node of the list,
   * and a pointer to the tail of the list.
   */
  typedef struct list_t
  {
    size_t		size;
    struct node_t*	head;
    struct node_t*	tail;
  } list_t;
  
  /**
   * @brief The list iterator structure allowing
   * to memorize a pointer to a `node_t` and going
   * forward and backward in the list.
   */
  typedef struct list_iterator_t
  {
    list_t*		list;
    node_t*		current;
    void*		data;
  } list_iterator_t;
  
  /**
   * @brief A predicate type to be used when iterating over
   * each node of the list.
   * @see list_iterate_over_nodes
   */
  typedef int (*list_predicate_t)(size_t index, node_t* node, void* data);
  
  /**
   * @brief Creates a new instance of a `list_t`.
   * @return a pointer to the created list.
   */
  list_t*	list_create();
  
  /**
   * @brief Destroys every element of the given `list` and
   * frees the memory allocated by the `list`. The given pointer
   * will not be usable after a call to this function.
   */
  void		list_destroy(list_t* list);
  
  /**
   * @brief Adds a new element to the `list`. This will cause a new `node_t`
   * to be created, holding the given `element` and pushed at the head of the
   * given `list`.
   * @return a pointer to the newly created node.
   */
  node_t*	list_push_front(list_t* list, void* element);
  
  /**
   * @brief Adds a new element to the `list`. This will cause a new `node_t`
   * to be created, holding the given `element` and pushed to the tail of the
   * given `list`.
   * @return a pointer to the newly created node.
   */
  node_t*	list_push_back(list_t* list, void* element);
  
  /**
   * @brief Allows to iterate over each node held by the list by pushing
   * each of them to the given `iterator`.
   */
  void		list_iterate_over_nodes(list_t* list, list_predicate_t iterator);
  
  /**
   * @brief Searches the list for the given `node`.
   * @return the found node if any; NULL otherwise.
   */
  node_t*	list_find_node(list_t* list, node_t* node);
  
  /**
   * @brief Finds an elemnt using the return value of the givn `predicate`.
   * @return the node matching the given predicate.
   */
  node_t*	list_find_node_if(list_t* list, list_predicate_t iterator, void* data);
  
  /**
   * @brief Removes the given `node` from the `list`
   * and frees the memory allocated by the `node`.
   * @return a positive value if the given `node` has
   * been successfully removed from the `list`, a negative
   * value otherwise.
   */
  int		list_remove_node(list_t* list, node_t* node);
  
  /**
   * @brief Conditionally removes a node from the list based on the return
   * value of the given `predicate`.
   * @return the number of removed nodes.
   */
  int		list_remove_node_if(list_t* list, list_predicate_t predicate, void* data);

  /**
   * @return the size of the given `kist` a.k.a the number of nodes currently
   * held by the list).
   */
  size_t	list_get_size(list_t* list);
  
  /**
   * @return a positive value if the given `list` is
   * empty, a negative value otherwise.
   */
  int		list_is_empty(list_t* list);
  
  void*		list_pop_node(list_t* list, node_t* node);
  
  void*		list_pop_back(list_t* list);
  
  void*		list_pop_front(list_t* list);
  
  list_iterator_t list_make_iterator(list_t* list, node_t* node);
  
  int		list_iterator_has_next(list_iterator_t* it);

  int		list_iterator_has_prev(list_iterator_t* it);
  
  node_t*	list_iterator_next(list_iterator_t* it);
  

#ifdef __cplusplus
}
#endif

#endif
