#include <iostream>
#include <algorithm>
using namespace std;

bool buscar_en_arreglo(float *array,float parametro){
    bool encontrado = false;
    for (int i= 0; i<(sizeof(array)/sizeof(array[0]));i++){
        if (array[i] == parametro) {
            encontrado = true;
            break;
        }
    }
    return encontrado;
}


 int main()
 {
    float search_num;
    float items[10] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,123.987};
    cout << "Ingresa el numero a buscar en el arreglo: ";
    cin >> search_num;
    bool res_find = buscar_en_arreglo(items,search_num);
    cout << res_find;
    if (res_find == true){
        cout << "El valor esta en el arreglo";
    }else
    {
        cout << "El valor no fue encontrado";
    }
    

     return 0;


 }
 