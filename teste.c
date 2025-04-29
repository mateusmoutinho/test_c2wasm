#include "c2wasm.c"
#include <stdio.h>
int i;
c2wasm_js_var getElementById(const char *id){
  c2wasm_js_var find_args = c2wasm_create_array();
  c2wasm_append_array_string(find_args,id);
  c2wasm_js_var element = c2wasm_call_object_prop(c2wasm_document,"getElementById",find_args);
  c2wasm_free(find_args);
  return element;
}

long increase_item(){
  c2wasm_js_var test_div = getElementById("test_div");
  char msg[100];
  sprintf(msg,"Hello World from C %d",i);
  c2wasm_set_object_prop_string(test_div,"innerHTML",msg);
  c2wasm_free(test_div);
  i++;


  return c2wasm_undefined;
}


int main(){
  c2wasm_start();
  c2wasm_set_object_prop_function(c2wasm_window,"increase_item",increase_item);
}