#include "genarraylib.h"
#include <stdio.h>
#include <string.h>

/*
This is the implementation of the functions in genarraylib.h. 
Please read the comments in genarraylib.h before you start working on this file.
*/

// You are allowed to define any helper functions or helper structs here.

// hint, a new struct for chunk index, element index may be helpful eventually.
// struct ...;
// typedef ...;


// hint, a new helper function for translating an index to the above struct may also be helpful.
// index -> struct;


generic_element_t create_generic_element(bool usable) {
    generic_element_t element;
    if (usable == true) {
	    element.type = GENERIC_TYPE_VOID; //if usable is true then set element type to Void
    } else {
	    element.type = GENERIC_TYPE_ERROR;
    }
    element.value.int_value = 0;  //set value to int 0

    return element;
}


generic_array_chunk_t create_generic_array_chunk(const int capacity) {
    generic_array_chunk_t chunk;
    if (capacity > MAX_ELEMENTS_PER_CHUNK) {
	    chunk.element_capacity = MAX_ELEMENTS_PER_CHUNK;
    } else if (capacity < 0) {               //if capacity is over the max elements assign element capacity to max elements
	    chunk.element_capacity = 0;     //if it is under 0 assign it to 0
    } else {
	    chunk.element_capacity = capacity; //otherwise assign it to capacity
    }
    for (int i = 0; i < MAX_ELEMENTS_PER_CHUNK; i++) {   //iterate through the elements array 
	    if (i < chunk.element_capacity) {
		    chunk.elements[i] = create_generic_element(true); //at indexes less then capacity assign Void element
	    } else {
		    chunk.elements[i] = create_generic_element(false); //Else assign error element
	    }
    }
    return chunk;
}


generic_array_t create_generic_array(const int chunk_capacity, const int per_chunk_capacities[], const int num_initial_elements) {
    generic_array_t array;
    int current_value = 0;                  //Initialize current value to hold number of elements initialized
    int remaining_elements = (num_initial_elements < 0) ? 0 : num_initial_elements;  //if initial elements is below 0 make remaining elements 0
    array.total_elements = 0;               //make array elements = 0

    if (chunk_capacity > MAX_CHUNKS) {
        array.chunk_capacity = MAX_CHUNKS;  //if chunk capacity is over the max elements assign element capacity to max elements
    } else if (chunk_capacity < 0) {
        array.chunk_capacity = 0;
    } else {
        array.chunk_capacity = chunk_capacity;
    }

    for (int i = 0; i < MAX_CHUNKS; i++) {
	    if (i < array.chunk_capacity) {              //for up to max chunks creat chunks with capacities determined by pre chunk capacities
		    array.chunks[i] = create_generic_array_chunk(per_chunk_capacities[i]);
	    } else {
		    array.chunks[i] = create_generic_array_chunk(0);   //after capacity of chunks is hit fill the rest with empty chunks
        }
    }
    for (int i = 0; i < array.chunk_capacity; i++) {
	    for (int j = 0; j < array.chunks[i].element_capacity;j++) {  //go through all chunks and elements and count when the type isnt ERROR
		    if (array.chunks[i].elements[j].type != GENERIC_TYPE_ERROR) {
			    array.total_elements ++;
		    }
	    }
    }
    
    for (int i = 0; i < array.chunk_capacity && remaining_elements > 0; i++) {    //go through all the chunks and elements in those chunks until no more remaining elements are left
        for (int j = 0; j < array.chunks[i].element_capacity && remaining_elements > 0; j++) {
            array.chunks[i].elements[j].type = GENERIC_TYPE_INT;                      //set the type of the element to int and the value to the current value
            array.chunks[i].elements[j].value.int_value = current_value++;
            remaining_elements--;                                                  //decrement remaining elements
        }
    }

    return array;
}


generic_element_t get_element(generic_array_t genarr, const int index) {
    generic_element_t error_element = {GENERIC_TYPE_ERROR, {0}};   //Create error element in case it fails
    int total_elements = 0;                      //Create total elements to find find the chunk the index is in

    for (int i = 0; i < genarr.chunk_capacity; i++) {     //go through each chunk and add the amount of elements to total element
        total_elements += genarr.chunks[i].element_capacity;
        if (index < total_elements) {                    //Once index is less than total elements stop iterating through chunks because we have found the right chunk
            int chunk_index = index - (total_elements - genarr.chunks[i].element_capacity); //get the index within the chunk by doing total elements - the capacity of the chunk we are on. 
            if (chunk_index < genarr.chunks[i].element_capacity) {   //then subtract index from that
                return genarr.chunks[i].elements[chunk_index];       //check if the chunk index is within the range for that chunk
            }
        }
    }
   
    return error_element;
}


generic_array_response_t set_element_int(generic_array_t genarr, const int index, const int value) {
    generic_array_response_t response = {false, genarr};
    int total_elements = 0;              //create response element and initialize total elements

    for (int i = 0; i < genarr.chunk_capacity; i++) {
        total_elements += genarr.chunks[i].element_capacity; //use the same code lines for the previous function to find the index within the chunk
        if (index < total_elements) {
            int chunk_index = index - (total_elements - genarr.chunks[i].element_capacity);
            if (chunk_index < genarr.chunks[i].element_capacity) {                    //Check if its type is not an error
                if (genarr.chunks[i].elements[chunk_index].type != GENERIC_TYPE_ERROR) {
                    genarr.chunks[i].elements[chunk_index].type = GENERIC_TYPE_INT;    //assign the integer value
                    genarr.chunks[i].elements[chunk_index].value.int_value = value;
                    response.success = true;
                }
		response.array = genarr;
                return response;
            }
        }
    }

    return response;
}

generic_array_response_t set_element_float(generic_array_t genarr, const int index, const float value) {
    generic_array_response_t response = {false, genarr};
    int total_elements = 0;              //create response element and initialize total elements

    for (int i = 0; i < genarr.chunk_capacity; i++) {
        total_elements += genarr.chunks[i].element_capacity; //use the same code lines for the previous function to find the index within the chunk
        if (index < total_elements) {
            int chunk_index = index - (total_elements - genarr.chunks[i].element_capacity);
            if (chunk_index < genarr.chunks[i].element_capacity) {                    //Check if its type is not an error
                if (genarr.chunks[i].elements[chunk_index].type != GENERIC_TYPE_ERROR) {
                    genarr.chunks[i].elements[chunk_index].type = GENERIC_TYPE_FLOAT;    //assign the float value
                    genarr.chunks[i].elements[chunk_index].value.float_value = value;
                    response.success = true;
                }
                response.array = genarr;
                return response;
            }
        }
    }

    return response;
}


generic_array_response_t set_element_double(generic_array_t genarr, const int index, const double value) {
    generic_array_response_t response = {false, genarr};
    int total_elements = 0;              //create response element and initialize total elements

    for (int i = 0; i < genarr.chunk_capacity; i++) {
        total_elements += genarr.chunks[i].element_capacity; //use the same code lines for the previous function to find the index within the chunk
        if (index < total_elements) {
            int chunk_index = index - (total_elements - genarr.chunks[i].element_capacity);
            if (chunk_index < genarr.chunks[i].element_capacity) {                    //Check if its type is not an error
                if (genarr.chunks[i].elements[chunk_index].type != GENERIC_TYPE_ERROR) {
                    genarr.chunks[i].elements[chunk_index].type = GENERIC_TYPE_DOUBLE;    //assign the Double value
                    genarr.chunks[i].elements[chunk_index].value.double_value = value;
                    response.success = true;
                }
                response.array = genarr;
                return response;
            }
        }
    }

    return response;
}


generic_array_response_t set_element_char(generic_array_t genarr, const int index, const char value) {
    generic_array_response_t response = {false, genarr};
    int total_elements = 0;              //create response element and initialize total elements

    for (int i = 0; i < genarr.chunk_capacity; i++) {
        total_elements += genarr.chunks[i].element_capacity; //use the same code lines for the previous function to find the index within the chunk
        if (index < total_elements) {
            int chunk_index = index - (total_elements - genarr.chunks[i].element_capacity);
            if (chunk_index < genarr.chunks[i].element_capacity) {                    //Check if its type is not an error
                if (genarr.chunks[i].elements[chunk_index].type != GENERIC_TYPE_ERROR) {
                    genarr.chunks[i].elements[chunk_index].type = GENERIC_TYPE_CHAR;    //assign the Char value
                    genarr.chunks[i].elements[chunk_index].value.char_value = value;
                    response.success = true;
                }
                response.array = genarr;
                return response;
            }
        }
    }

    return response;
}


generic_array_response_t set_element_short(generic_array_t genarr, const int index, const short value) {
    generic_array_response_t response = {false, genarr};
    int total_elements = 0;              //create response element and initialize total elements

    for (int i = 0; i < genarr.chunk_capacity; i++) {
        total_elements += genarr.chunks[i].element_capacity; //use the same code lines for the previous function to find the index within the chunk
        if (index < total_elements) {
            int chunk_index = index - (total_elements - genarr.chunks[i].element_capacity);
            if (chunk_index < genarr.chunks[i].element_capacity) {                    //Check if its type is not an error
                if (genarr.chunks[i].elements[chunk_index].type != GENERIC_TYPE_ERROR) {
                    genarr.chunks[i].elements[chunk_index].type = GENERIC_TYPE_SHORT;    //assign the Short value
                    genarr.chunks[i].elements[chunk_index].value.short_value = value;
                    response.success = true;
                }
                response.array = genarr;
                return response;
            }
        }
    }

    return response;
}


generic_array_response_t set_element_bool(generic_array_t genarr, const int index, const bool value) {
    generic_array_response_t response = {false, genarr};
    int total_elements = 0;              //create response element and initialize total elements

    for (int i = 0; i < genarr.chunk_capacity; i++) {
        total_elements += genarr.chunks[i].element_capacity; //use the same code lines for the previous function to find the index within the chunk
        if (index < total_elements) {
            int chunk_index = index - (total_elements - genarr.chunks[i].element_capacity);
            if (chunk_index < genarr.chunks[i].element_capacity) {                    //Check if its type is not an error
                if (genarr.chunks[i].elements[chunk_index].type != GENERIC_TYPE_ERROR) {
                    genarr.chunks[i].elements[chunk_index].type = GENERIC_TYPE_BOOL;    //assign the Bool value
                    genarr.chunks[i].elements[chunk_index].value.bool_value = value;
                    response.success = true;
                }
                response.array = genarr;
                return response;
            }
        }
    }

    return response;
}


generic_array_response_t set_element_string(generic_array_t genarr, const int index, const char value[]) {
    generic_array_response_t response = {false, genarr};
    int total_elements = 0;              //create response element and initialize total elements

    for (int i = 0; i < genarr.chunk_capacity; i++) {
        total_elements += genarr.chunks[i].element_capacity; //use the same code lines for the previous function to find the index within the chunk
        if (index < total_elements) {
            int chunk_index = index - (total_elements - genarr.chunks[i].element_capacity);
            if (chunk_index < genarr.chunks[i].element_capacity) {                    //Check if its type is not an error
                if (genarr.chunks[i].elements[chunk_index].type != GENERIC_TYPE_ERROR) {
                    genarr.chunks[i].elements[chunk_index].type = GENERIC_TYPE_STRING;    //assign the String value
                    strncpy(genarr.chunks[i].elements[chunk_index].value.string_value, value, MAX_CHAR_ARRAY_LENGTH - 1);  //Use strincpy and ensure null termination
		    genarr.chunks[i].elements[chunk_index].value.string_value[MAX_CHAR_ARRAY_LENGTH - 1] = '\0';
                    response.success = true;
                }
                response.array = genarr;
                return response;
            }
        }
    }

    return response;
}


bool is_equal_element(generic_element_t elem1, generic_element_t elem2) {
    if (elem1.type != elem2.type) {
        return false;         //If element types are different return false
    }

    switch (elem1.type) {
        case GENERIC_TYPE_INT:
            return elem1.value.int_value == elem2.value.int_value;
        case GENERIC_TYPE_FLOAT:                                     //Use switch to check for all case of types 
            return elem1.value.float_value == elem2.value.float_value;
        case GENERIC_TYPE_DOUBLE:
            return elem1.value.double_value == elem2.value.double_value;
        case GENERIC_TYPE_CHAR:
            return elem1.value.char_value == elem2.value.char_value;
        case GENERIC_TYPE_SHORT:
            return elem1.value.short_value == elem2.value.short_value;
        case GENERIC_TYPE_BOOL:
            return elem1.value.bool_value == elem2.value.bool_value;
        case GENERIC_TYPE_STRING:
            return strcmp(elem1.value.string_value, elem2.value.string_value) == 0;
        case GENERIC_TYPE_VOID:
        case GENERIC_TYPE_ERROR:         //Void and Error are always true if they are both that type
            return true;
        default:
            return false;
    }
}


bool is_equal(generic_array_t genarr1, generic_array_t genarr2) {
     if (genarr1.total_elements != genarr2.total_elements) {
        return false;      //if the arrays have different total elements its false
    }

    for (int i = 0; i < genarr1.total_elements; i++) {
        generic_element_t elem1 = get_element(genarr1, i);  //name the element from the first array
        generic_element_t elem2 = get_element(genarr2, i);  //name the element of same index from second array

        if (!is_equal_element(elem1, elem2)) {    //if they dont equal return false
            return false;
        }   
    }              //if we get through whole array then return true

    return true;
}
