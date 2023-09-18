#ifndef SORTS_H_
#define SORTS_H_

#include <vector>
#include <list>
#include <cstring>
#include <string>

template <class T>// T se rellena por un tipo de dato
class Sorts {
private:
  int convert(std::string, int);
  
	void copyArray(std::vector<T>&, std::vector<T>&, int, int);
	void mergeArray(std::vector<T>&, std::vector<T>&, int, int, int);
	void mergeSplit(std::vector<T>&, std::vector<T>&, int, int);
public:
	std::vector<T> ordenaMerge(std::vector<T>&);
  std::vector<int> vectorASCII(std::string);
	int busqBinaria(std::vector<T>&,std::string);
	int busqBinaria_aux(std::vector<T>&, int, int, std::string);

  
}; 
template <class T>
int Sorts<T>::convert(std::string s,int p) {
  std::string palabra;
  int b;
  palabra=s;
  b=(int)palabra[p];
  return b;
}
template <class T>
std::vector<int> Sorts<T>::vectorASCII(std::string s)  
{
    std::vector <int> nuevo_vector; 
    int valorAscii;
    for (int i = 0; i < s.length(); i++) 
    {
      valorAscii = (int)s[i];
      nuevo_vector.push_back(valorAscii);
    }
    return nuevo_vector;
}
template <class T>
void Sorts<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}
template <class T>	
void Sorts<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {
	int i, j, k;
	i = low;
	j = mid + 1;
	k = low;
	while (i <= mid &&j <= high) {
    int n;
    n=0;
    while (convert(A[i],n)==convert(A[j],n)) {
			n++;
		}
		if (convert(A[i],n)<convert(A[j],n)) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (; j <= high; j++) { //termina de poner los ultimos valores
			B[k++] = A[j];
		}
	} else {
		for (; i <= mid; i++) { //termina de poner los ultimos valores
			B[k++] = A[i];
		}
	}
}
template <class T>
void Sorts<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	int mid;

	if ( (high - low) < 1 ) {
		return;
	}
	mid = (high + low) / 2;
	mergeSplit(A, B, low, mid);
	mergeSplit(A, B, mid + 1, high);
	mergeArray(A, B, low, mid, high);
	copyArray(A, B, low, high);
}
template <class T>
std::vector<T> Sorts<T>::ordenaMerge(std::vector<T> &source) {
	std::vector<T> v(source);
	std::vector<T> tmp(v.size());

	mergeSplit(source, tmp, 0, source.size() - 1);
	return source;
}

//HOLA 
template <class T>
int Sorts<T>::busqBinaria_aux (std::vector<T>&source, int low, int high, std::string valor){
    int mid;
	if(low <= high) {
		mid=(low+high)/2;
		if(convert(valor,0)==convert(source[mid],0)){
      if(vectorASCII(valor)==vectorASCII(source[mid])){
      return mid;
        }
      else if(vectorASCII(valor)==vectorASCII(source[mid-1])){
      return mid-1;
        }
      else if(vectorASCII(valor)==vectorASCII(source[mid+1])){
      return mid+1;
        }
		}
		else if(convert(valor,0)<convert(source[mid],0)){
			return busqBinaria_aux(source,low,mid-1,valor);
		}
		else{
			return busqBinaria_aux(source,mid+1,high,valor);
		}
	}
	return -1;
}
template <class T>
int Sorts<T>::busqBinaria (std::vector<T> &source, std::string valor){
	int low=0;
	int longitud=source.size(); 
	int high=longitud-1;
	int mid;
	mid=(low+high)/2;
	if(convert(valor,0)==convert(source[mid],0)){
    if(vectorASCII(valor)==vectorASCII(source[mid])){
      return mid;
        }
      else if(vectorASCII(valor)==vectorASCII(source[mid-1])){
      return mid-1;
        }
      else if(vectorASCII(valor)==vectorASCII(source[mid+1])){
      return mid+1;
        }
	}
	else {
		mid = (low+high) / 2;
		if(convert(valor,0)<convert(source[mid],0)){
			return busqBinaria_aux(source,low,mid-1,valor);
		}
		else{
			return busqBinaria_aux(source,mid+1,high,valor);
		}
	}
	return busqBinaria_aux(source, 0, longitud - 1, valor);
}
#endif /* SORTS_H_ */