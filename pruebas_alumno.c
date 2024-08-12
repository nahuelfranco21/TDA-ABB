#include "pa2m.h"
#include "src/abb.h"

typedef struct cosa {
	int clave;
	char contenido[10];
} cosa;

typedef struct pruebas_aux {
	int *vector;
	int posicion;
	size_t tope;
} pruebas_t;

cosa *crear_cosa(int clave)
{
	cosa *c = (cosa *)malloc(sizeof(cosa));
	if (c)
		c->clave = clave;
	return c;
}

int comparar_cosas(void *c1, void *c2)
{
	cosa *cosa1 = c1;
	cosa *cosa2 = c2;
	return cosa1->clave - cosa2->clave;
}

void destruir_cosa(cosa *c)
{
	free(c);
}

void destructor_de_cosas(void *c)
{
	cosa *cosa = c;
	if (cosa)
		destruir_cosa(c);
}

int comparador(void *elemento_1, void *elemento_2)
{
	int *valor_1 = (int *)elemento_1;
	int *valor_2 = (int *)elemento_2;

	if (valor_1 == valor_2) {
		return 0;
	}

	return 1;
}

void crear_arbol_no_devuelve_error()
{
	abb_t *arbol = abb_crear(comparador);

	pa2m_afirmar(arbol != NULL, "Se creo bien el arbol");

	free(arbol);
}

void insertar_un_solo_elemento_no_devuelve_error()
{
	abb_t *arbol = abb_crear(comparador);
	arbol = abb_insertar(arbol, (void *)12);

	pa2m_afirmar(arbol != NULL, "El arbol se creo de forma correcta");
	pa2m_afirmar(abb_tamanio(arbol) == 1,
		     "El arbol inserto bien y el tamaño es correcto");

	abb_destruir(arbol);
}

void insertar_muchos_elementos_en_el_arbol_lo_hace_bien()
{
	abb_t *arbol = abb_crear(comparador);

	abb_insertar(arbol, (void *)1);
	abb_insertar(arbol, (void *)2);
	abb_insertar(arbol, (void *)3);
	abb_insertar(arbol, (void *)4);
	abb_insertar(arbol, (void *)5);
	abb_insertar(arbol, (void *)6);
	abb_insertar(arbol, (void *)7);
	abb_insertar(arbol, (void *)8);
	abb_insertar(arbol, (void *)9);
	abb_insertar(arbol, (void *)10);
	abb_insertar(arbol, (void *)1);
	abb_insertar(arbol, (void *)2);
	abb_insertar(arbol, (void *)3);
	abb_insertar(arbol, (void *)4);
	abb_insertar(arbol, (void *)5);
	abb_insertar(arbol, (void *)6);
	abb_insertar(arbol, (void *)7);
	abb_insertar(arbol, (void *)8);
	abb_insertar(arbol, (void *)9);
	abb_insertar(arbol, (void *)10);

	pa2m_afirmar(arbol != NULL, "El arbol no es nulo");
	pa2m_afirmar(
		abb_tamanio(arbol) == 20,
		"El arbol inserto bien todos los elementos porque su tamaño es correcto");

	abb_destruir(arbol);
}

void insertar_distintos_tipos_de_elementos_lo_hace_bien()
{
	abb_t *arbol = abb_crear(comparador);

	abb_insertar(arbol, (void *)1);
	abb_insertar(arbol, (void *)"ESO");
	abb_insertar(arbol, (void *)"BOCA");
	abb_insertar(arbol, (void *)4);
	abb_insertar(arbol, (void *)'A');
	abb_insertar(arbol, (void *)"DIa");
	abb_insertar(arbol, (void *)7);
	abb_insertar(arbol, (void *)8);
	abb_insertar(arbol, (void *)9);
	abb_insertar(arbol, (void *)10);

	pa2m_afirmar(
		abb_tamanio(arbol) == 10,
		"El arbol inserto bien todos los elementos, aunque sean de distinto tipo");

	abb_destruir(arbol);
}

void buscar_elemento_existente_lo_hace_bien()
{
	abb_t *arbol = abb_crear(comparador);
	abb_insertar(arbol, (void *)12);
	abb_insertar(arbol, (void *)1);
	void *buscado = abb_buscar(arbol, (void *)12);

	pa2m_afirmar(arbol != NULL && buscado, "El elemento se encontro");

	abb_destruir(arbol);
}

void buscar_elemento_inexistente_devuelve_NULL()
{
	abb_t *arbol = abb_crear(comparador);
	abb_insertar(arbol, (void *)12);
	abb_insertar(arbol, (void *)1);
	void *buscado = abb_buscar(arbol, (void *)10);

	pa2m_afirmar(buscado == NULL,
		     "El elemento no se encontro por lo tanto devuelve NULL");

	abb_destruir(arbol);
}

void buscar_entre_muchos_elementos_lo_hace_bien()
{
	abb_t *arbol = abb_crear(comparador);
	abb_insertar(arbol, (void *)1);
	abb_insertar(arbol, (void *)2);
	abb_insertar(arbol, (void *)3);
	abb_insertar(arbol, (void *)4);
	abb_insertar(arbol, (void *)5);
	abb_insertar(arbol, (void *)6);
	abb_insertar(arbol, (void *)7);
	abb_insertar(arbol, (void *)8);
	abb_insertar(arbol, (void *)9);
	abb_insertar(arbol, (void *)10);
	abb_insertar(arbol, (void *)1);
	abb_insertar(arbol, (void *)2);
	abb_insertar(arbol, (void *)3);
	abb_insertar(arbol, (void *)"BOCA");
	abb_insertar(arbol, (void *)5);
	abb_insertar(arbol, (void *)6);
	abb_insertar(arbol, (void *)7);
	abb_insertar(arbol, (void *)8);
	abb_insertar(arbol, (void *)9);
	abb_insertar(arbol, (void *)10);
	void *buscado = abb_buscar(arbol, (void *)"BOCA");

	pa2m_afirmar(arbol != NULL && buscado,
		     "El elemento se encontro entre muchos insertados");

	abb_destruir(arbol);
}

void buscar_palabras_en_el_arbol()
{
	abb_t *arbol = abb_crear(comparador);
	abb_insertar(arbol, (void *)1);
	abb_insertar(arbol, (void *)2);
	abb_insertar(arbol, (void *)3);
	abb_insertar(arbol, (void *)4);
	abb_insertar(arbol, (void *)5);
	abb_insertar(arbol, (void *)6);
	abb_insertar(arbol, (void *)7);
	abb_insertar(arbol, (void *)8);
	abb_insertar(arbol, (void *)9);
	abb_insertar(arbol, (void *)10);
	abb_insertar(arbol, (void *)1);
	abb_insertar(arbol, (void *)2);
	abb_insertar(arbol, (void *)3);
	abb_insertar(arbol, (void *)"Kendrick Lamar");
	abb_insertar(arbol, (void *)5);
	abb_insertar(arbol, (void *)6);
	abb_insertar(arbol, (void *)7);
	abb_insertar(arbol, (void *)8);
	abb_insertar(arbol, (void *)9);
	abb_insertar(arbol, (void *)10);

	void *buscado = abb_buscar(arbol, (void *)"Kendrick Lamar");

	pa2m_afirmar(arbol != NULL && buscado,
		     "Se encontro la palabra buscada");

	abb_destruir(arbol);
}

void buscar_numero_en_el_arbol()
{
	abb_t *arbol = abb_crear(comparador);
	abb_insertar(arbol, (void *)1);
	abb_insertar(arbol, (void *)2);
	abb_insertar(arbol, (void *)3);
	abb_insertar(arbol, (void *)4);
	abb_insertar(arbol, (void *)5);
	abb_insertar(arbol, (void *)6);
	abb_insertar(arbol, (void *)7);
	abb_insertar(arbol, (void *)8);
	abb_insertar(arbol, (void *)9);
	abb_insertar(arbol, (void *)10);
	abb_insertar(arbol, (void *)1);
	abb_insertar(arbol, (void *)2);
	abb_insertar(arbol, (void *)3);
	abb_insertar(arbol, (void *)"Kendrick Lamar");
	abb_insertar(arbol, (void *)5);
	abb_insertar(arbol, (void *)6);
	abb_insertar(arbol, (void *)7);
	abb_insertar(arbol, (void *)8);
	abb_insertar(arbol, (void *)9);
	abb_insertar(arbol, (void *)10);

	void *buscado = abb_buscar(arbol, (void *)6);

	pa2m_afirmar(arbol != NULL && buscado, "Se encontro el numero buscado");

	abb_destruir(arbol);
}

void comprobar_que_el_arbol_esta_vacio()
{
	abb_t *arbol = abb_crear(comparador);
	abb_vacio(arbol);

	pa2m_afirmar(abb_tamanio(arbol) == 0, "El arbol esta vacio");

	abb_destruir(arbol);
}

void agregar_eliminar_y_que_este_vacio()
{
	abb_t *arbol = abb_crear(comparador);

	abb_insertar(arbol, (void *)1);
	abb_insertar(arbol, (void *)2);
	abb_insertar(arbol, (void *)3);

	abb_quitar(arbol, (void *)3);
	abb_quitar(arbol, (void *)2);
	abb_quitar(arbol, (void *)1);

	pa2m_afirmar(
		abb_vacio(arbol),
		"Agregue elementos, despues los elimine y el arbol queda vacio");

	abb_destruir(arbol);
}

void elimino_algunos_elementos_y_el_arbol_no_queda_vacio()
{
	abb_t *arbol = abb_crear(comparador);

	abb_insertar(arbol, (void *)1);
	abb_insertar(arbol, (void *)2);
	abb_insertar(arbol, (void *)3);
	abb_insertar(arbol, (void *)4);
	abb_insertar(arbol, (void *)5);
	abb_insertar(arbol, (void *)6);

	abb_quitar(arbol, (void *)6);
	abb_quitar(arbol, (void *)5);
	abb_quitar(arbol, (void *)4);
	abb_quitar(arbol, (void *)3);

	pa2m_afirmar(
		!abb_vacio(arbol),
		"Elimine solo algunos elementos y el arbol no queda vacio");

	abb_destruir(arbol);
}

void comprobar_que_el_tamanio_es_el_correcto()
{
	abb_t *arbol = abb_crear(comparador);

	abb_insertar(arbol, (void *)1);
	abb_insertar(arbol, (void *)2);
	abb_insertar(arbol, (void *)3);
	abb_insertar(arbol, (void *)4);
	abb_insertar(arbol, (void *)5);
	abb_insertar(arbol, (void *)6);
	abb_insertar(arbol, (void *)7);
	abb_insertar(arbol, (void *)8);
	abb_insertar(arbol, (void *)9);
	abb_insertar(arbol, (void *)10);

	pa2m_afirmar(abb_tamanio(arbol) == 10,
		     "El arbol tiene el tamaño correcto de elementos");

	abb_destruir(arbol);
}

void agrego_elimino_el_tamaño_es_correcto()
{
	abb_t *arbol = abb_crear(comparador);

	abb_insertar(arbol, (void *)1);
	abb_insertar(arbol, (void *)2);
	abb_insertar(arbol, (void *)3);
	abb_insertar(arbol, (void *)4);
	abb_insertar(arbol, (void *)5);

	abb_quitar(arbol, (void *)5);
	abb_quitar(arbol, (void *)4);
	abb_quitar(arbol, (void *)3);

	pa2m_afirmar(
		abb_tamanio(arbol) == 2,
		"Despues de eliminar algunos elementos, el tamaño es correcto");

	abb_destruir(arbol);
}

void eliminar_un_elemento_del_arbol()
{
	abb_t *arbol = abb_crear(comparador);

	abb_insertar(arbol, (void *)9);
	abb_insertar(arbol, (void *)8);
	abb_insertar(arbol, (void *)2);
	abb_insertar(arbol, (void *)11);
	abb_insertar(arbol, (void *)12);
	abb_insertar(arbol, (void *)4);
	abb_insertar(arbol, (void *)1);
	abb_insertar(arbol, (void *)10);
	abb_insertar(arbol, (void *)14);

	abb_quitar(arbol, (void *)10);

	pa2m_afirmar(abb_tamanio(arbol) == 8,
		     "El arbol tiene el tamaño correcto de elementos");

	abb_destruir(arbol);
}

void eliminar_multiples_elementos_del_arbol()
{
	abb_t *arbol = abb_crear(comparador);

	abb_insertar(arbol, (void *)9);
	abb_insertar(arbol, (void *)8);
	abb_insertar(arbol, (void *)2);
	abb_insertar(arbol, (void *)11);
	abb_insertar(arbol, (void *)12);
	abb_insertar(arbol, (void *)4);
	abb_insertar(arbol, (void *)1);
	abb_insertar(arbol, (void *)10);
	abb_insertar(arbol, (void *)14);

	abb_quitar(arbol, (void *)10);
	abb_quitar(arbol, (void *)8);
	abb_quitar(arbol, (void *)2);
	abb_quitar(arbol, (void *)4);

	pa2m_afirmar(abb_tamanio(arbol) == 5,
		     "El arbol tiene el tamaño correcto de elementos");

	abb_destruir(arbol);
}

void eliminar_elemento_inexistente_mantiene_el_mismo_tamaño()
{
	abb_t *arbol = abb_crear(comparador);

	abb_insertar(arbol, (void *)9);
	abb_insertar(arbol, (void *)8);
	abb_insertar(arbol, (void *)2);
	abb_insertar(arbol, (void *)11);
	abb_insertar(arbol, (void *)12);
	abb_insertar(arbol, (void *)4);
	abb_insertar(arbol, (void *)1);
	abb_insertar(arbol, (void *)10);
	abb_insertar(arbol, (void *)14);

	abb_quitar(arbol, (void *)100);

	pa2m_afirmar(
		abb_tamanio(arbol) == 9,
		"Si elimino un elemento inexistente el arbol sigue con el tamaño correcto de elementos");

	abb_destruir(arbol);
}

void arbol_NULL_en_abb_crear()
{
	abb_t *arbol = abb_crear(NULL);

	pa2m_afirmar(!arbol, "Cuando el abb es NULL devuelve NULL");

	free(arbol);
}

void insertar_NULL_en_abb_insertar()
{
	abb_t *arbol = NULL;

	abb_insertar(arbol, (void *)1);

	pa2m_afirmar(!arbol,
		     "Devuelvo NULL en abb_insertar cuando el abb es invalido");

	abb_destruir(arbol);
}

void insertar_un_elemento_NULL_en_abb_insertar()
{
	abb_t *arbol = abb_crear(comparador);

	void *elemento = NULL;

	abb_quitar(arbol, elemento);

	pa2m_afirmar(
		!elemento,
		"Recibo un elemento NULL en abb_insertar, por lo tanto devuelvo NULL");

	abb_destruir(arbol);
}

void arbol_NULL_en_abb_quitar()
{
	abb_t *arbol = NULL;

	abb_insertar(arbol, (void *)1);

	pa2m_afirmar(!arbol,
		     "Devuelvo NULL en abb_quitar cuando el abb es invalido");

	abb_destruir(arbol);
}

void insertar_un_elemento_NULL_en_abb_quitar()
{
	abb_t *arbol = abb_crear(comparador);

	void *elemento = NULL;

	abb_quitar(arbol, elemento);

	pa2m_afirmar(
		!elemento,
		"Recibo un elemento NULL en abb_quitar, por lo tanto devuelvo NULL");

	abb_destruir(arbol);
}

void arbol_NULL_en_abb_buscar()
{
	abb_t *arbol = NULL;

	abb_insertar(arbol, (void *)1);

	pa2m_afirmar(!arbol,
		     "Devuelvo NULL en abb_buscar cuando el abb es invalido");
}

void insertar_un_elemento_NULL_en_abb_buscar()
{
	abb_t *arbol = abb_crear(comparador);

	void *elemento = NULL;

	abb_quitar(arbol, elemento);

	pa2m_afirmar(
		!elemento,
		"Recibo un elemento NULL en abb_buscar, por lo tanto devuelvo NULL");

	abb_destruir(arbol);
}

void abb_NULL_en_abb_vacio()
{
	abb_t *arbol = NULL;

	abb_vacio(arbol);

	pa2m_afirmar(!arbol, "El arbol esta vacio por lo tanto devuelve false");
}

void abb_NULL_en_abb_tamanio()
{
	abb_t *arbol = NULL;

	abb_tamanio(arbol);

	pa2m_afirmar(!arbol, "El arbol esta vacio por lo tanto el tamaño es 0");
}

void abb_NULL_en_abb_con_cada_elemento()
{
	abb_t *arbol = NULL;

	abb_con_cada_elemento(arbol, 0, NULL, NULL);

	pa2m_afirmar(!arbol,
		     "El arbol es incorrecto por lo tanto devuelve NULL");
}

void funcion_NULL_en_abb_con_cada_elemento()
{
	abb_t *arbol = abb_crear(comparador);

	bool (*funcion)(void *, void *) = NULL;

	abb_con_cada_elemento(arbol, 0, funcion, NULL);

	pa2m_afirmar(!funcion,
		     "La funcion es incorrecta, por lo tanto devuelve NULL");

	abb_destruir(arbol);
}

void abb_NULL_en_abb_recorrer()
{
	abb_t *arbol = NULL;

	void *array[10];

	abb_recorrer(arbol, INORDEN, array, 10);

	pa2m_afirmar(!arbol, "El abb es incorrecto, devuelvo 0");
}

void array_NULL_en_abb_recorrer()
{
	abb_t *arbol = abb_crear(comparador);

	void **array = NULL;

	abb_recorrer(arbol, INORDEN, array, 10);

	pa2m_afirmar(!array, "El array es incorrecto, devuelvo 0");

	abb_destruir(arbol);
}

void tamanio_0_del_array_en_abb_recorrer()
{
	abb_t *arbol = abb_crear(comparador);

	void **array = 0;
	size_t tamaño = 0;

	abb_recorrer(arbol, INORDEN, array, tamaño);

	pa2m_afirmar(!(tamaño > 0), "El tamaño es 0, por lo tanto devuelvo 0");

	abb_destruir(arbol);
}

void recorrido_incorrecto_en_abb_recorrer()
{
	abb_t *arbol = abb_crear(comparador);

	void **array = 0;
	size_t tamaño = 0;
	abb_recorrido recorrido = 9;

	abb_recorrer(arbol, recorrido, array, tamaño);

	pa2m_afirmar(!(recorrido >= 0 && recorrido <= 2),
		     "El recorrido es incorrecto, por lo tanto devuelvo 0");

	abb_destruir(arbol);
}

bool comparar_elementos_para_recorrer(void *elemento, void *aux)
{
	pruebas_t *prueba = (pruebas_t *)aux;

	pa2m_afirmar(prueba->vector[prueba->posicion] ==
			     ((cosa *)elemento)->clave,
		     "El elemento en la posición es correcto");

	prueba->posicion++;
	return true;
}

void prueba_sobre_recorrido(abb_t *arbol, abb_recorrido orden,
			    int *vector_orden, size_t tamaño_vector,
			    const char *mensaje)
{
	pruebas_t prueba;

	prueba.vector = vector_orden;
	prueba.tope = tamaño_vector;
	prueba.posicion = 0;

	abb_con_cada_elemento(arbol, orden, comparar_elementos_para_recorrer,
			      &prueba);
}

void abb_recorrer_devuelve_la_cantidad_de_elementos_correcta_en_el_recorrido(
	abb_t *arbol, size_t tipo_recorrido, const char *mensaje)
{
	size_t tamanio_array = abb_tamanio(arbol);
	void *array[tamanio_array];
	size_t cantidad =
		abb_recorrer(arbol, tipo_recorrido, array, tamanio_array);

	pa2m_afirmar(cantidad == tamanio_array, mensaje);

	abb_destruir_todo(arbol, destructor_de_cosas);
}

void recorrer_inorden_lo_hace_bien_y_los_elementos_comparados_son_correctos()
{
	abb_t *arbol = abb_crear(comparar_cosas);

	abb_insertar(arbol, crear_cosa(15));
	abb_insertar(arbol, crear_cosa(1));
	abb_insertar(arbol, crear_cosa(9));
	abb_insertar(arbol, crear_cosa(7));
	abb_insertar(arbol, crear_cosa(4));

	int orden_esperado[] = { 1, 4, 7, 9, 15 };

	prueba_sobre_recorrido(
		arbol, INORDEN, orden_esperado, abb_tamanio(arbol),
		"La cantidad de elementos es correcta en inorden");
	abb_destruir_todo(arbol, destructor_de_cosas);
}

void la_cantidad_de_elementos_es_correcta_en_inorden()
{
	abb_t *arbol = abb_crear(comparador);

	abb_insertar(arbol, crear_cosa(15));
	abb_insertar(arbol, crear_cosa(1));
	abb_insertar(arbol, crear_cosa(9));
	abb_insertar(arbol, crear_cosa(15));
	abb_insertar(arbol, crear_cosa(1));
	abb_insertar(arbol, crear_cosa(9));

	abb_recorrer_devuelve_la_cantidad_de_elementos_correcta_en_el_recorrido(
		arbol, INORDEN,
		"La cantidad de elementos en el recorrido inorden es correcta");
}

void recorrer_preorden_lo_hace_bien_y_los_elementos_comparados_son_correctos()
{
	abb_t *arbol = abb_crear(comparar_cosas);

	abb_insertar(arbol, crear_cosa(15));
	abb_insertar(arbol, crear_cosa(1));
	abb_insertar(arbol, crear_cosa(9));
	abb_insertar(arbol, crear_cosa(7));
	abb_insertar(arbol, crear_cosa(4));

	int orden_esperado[] = { 15, 1, 9, 7, 4 };

	prueba_sobre_recorrido(
		arbol, PREORDEN, orden_esperado, abb_tamanio(arbol),
		"La cantidad de elementos es correcta en preorden");

	abb_destruir_todo(arbol, destructor_de_cosas);
}

void la_cantidad_de_elementos_es_correcta_en_preorden()
{
	abb_t *arbol = abb_crear(comparador);

	abb_insertar(arbol, crear_cosa(15));
	abb_insertar(arbol, crear_cosa(1));

	abb_recorrer_devuelve_la_cantidad_de_elementos_correcta_en_el_recorrido(
		arbol, PREORDEN,
		"La cantidad de elementos en el recorrido postorden es correcta");
}

void si_el_arbol_esta_vacio_devuelve_cero_sin_importar_el_tipo_de_recorrido(
	size_t tipo_recorrido, const char *mensaje)
{
	abb_t *arbol = abb_crear(comparador);
	abb_recorrer_devuelve_la_cantidad_de_elementos_correcta_en_el_recorrido(
		arbol, tipo_recorrido, mensaje);
}

void recorrer_postorden_lo_hace_bien_y_los_elementos_comparados_son_correctos()
{
	abb_t *arbol = abb_crear(comparar_cosas);

	abb_insertar(arbol, crear_cosa(15));
	abb_insertar(arbol, crear_cosa(1));
	abb_insertar(arbol, crear_cosa(9));
	abb_insertar(arbol, crear_cosa(7));
	abb_insertar(arbol, crear_cosa(4));

	int orden_esperado[] = { 4, 7, 9, 1, 15 };

	prueba_sobre_recorrido(
		arbol, POSTORDEN, orden_esperado, abb_tamanio(arbol),
		"La cantidad de elementos es correcta en preorden");

	abb_destruir_todo(arbol, destructor_de_cosas);
}

void la_cantidad_de_elementos_es_correcta_en_postorden()
{
	abb_t *arbol = abb_crear(comparador);

	abb_insertar(arbol, crear_cosa(15));
	abb_insertar(arbol, crear_cosa(1));
	abb_insertar(arbol, crear_cosa(9));
	abb_insertar(arbol, crear_cosa(15));
	abb_insertar(arbol, crear_cosa(1));
	abb_insertar(arbol, crear_cosa(9));

	abb_recorrer_devuelve_la_cantidad_de_elementos_correcta_en_el_recorrido(
		arbol, POSTORDEN,
		"La cantidad de elementos en el recorrido postorden es correcta");
}

int main()
{
	pa2m_nuevo_grupo("CREAR EL ARBOL");
	crear_arbol_no_devuelve_error();

	pa2m_nuevo_grupo("INSERTAR ELEMENTOS");
	insertar_un_solo_elemento_no_devuelve_error();
	insertar_muchos_elementos_en_el_arbol_lo_hace_bien();
	insertar_distintos_tipos_de_elementos_lo_hace_bien();

	pa2m_nuevo_grupo("PRUEBAS DE ELIMINACION");
	eliminar_un_elemento_del_arbol();
	eliminar_multiples_elementos_del_arbol();
	eliminar_elemento_inexistente_mantiene_el_mismo_tamaño();

	pa2m_nuevo_grupo("BUSCAR EN EL ARBOL");
	buscar_elemento_existente_lo_hace_bien();
	buscar_elemento_inexistente_devuelve_NULL();
	buscar_entre_muchos_elementos_lo_hace_bien();
	buscar_palabras_en_el_arbol();
	buscar_numero_en_el_arbol();

	pa2m_nuevo_grupo("COMPROBACIONES SOBRE EL ARBOL");
	comprobar_que_el_arbol_esta_vacio();
	agregar_eliminar_y_que_este_vacio();
	elimino_algunos_elementos_y_el_arbol_no_queda_vacio();
	comprobar_que_el_tamanio_es_el_correcto();
	agrego_elimino_el_tamaño_es_correcto();

	pa2m_nuevo_grupo("PRUEBAS CON NULL");
	arbol_NULL_en_abb_crear();
	insertar_NULL_en_abb_insertar();
	insertar_un_elemento_NULL_en_abb_insertar();
	arbol_NULL_en_abb_quitar();
	insertar_un_elemento_NULL_en_abb_quitar();
	arbol_NULL_en_abb_buscar();
	insertar_un_elemento_NULL_en_abb_buscar();
	abb_NULL_en_abb_vacio();
	abb_NULL_en_abb_tamanio();
	abb_NULL_en_abb_con_cada_elemento();
	funcion_NULL_en_abb_con_cada_elemento();
	abb_NULL_en_abb_recorrer();
	array_NULL_en_abb_recorrer();
	tamanio_0_del_array_en_abb_recorrer();
	recorrido_incorrecto_en_abb_recorrer();

	pa2m_nuevo_grupo("RECORRIDOS DEL ARBOL");
	si_el_arbol_esta_vacio_devuelve_cero_sin_importar_el_tipo_de_recorrido(
		INORDEN,
		"El arbol no se cargo, por lo tanto la cantidad de elementos es 0 en INORDEN");
	si_el_arbol_esta_vacio_devuelve_cero_sin_importar_el_tipo_de_recorrido(
		PREORDEN,
		"El arbol no se cargo, por lo tanto la cantidad de elementos es 0 en PREORDEN");
	si_el_arbol_esta_vacio_devuelve_cero_sin_importar_el_tipo_de_recorrido(
		POSTORDEN,
		"El arbol no se cargo, por lo tanto la cantidad de elementos es 0 en POSTORDEN");
	pa2m_nuevo_grupo("Recorrido inorden");
	recorrer_inorden_lo_hace_bien_y_los_elementos_comparados_son_correctos();
	la_cantidad_de_elementos_es_correcta_en_inorden();
	pa2m_nuevo_grupo("Recorrido preorden");
	recorrer_preorden_lo_hace_bien_y_los_elementos_comparados_son_correctos();
	la_cantidad_de_elementos_es_correcta_en_preorden();
	pa2m_nuevo_grupo("Recorrido postorden");
	recorrer_postorden_lo_hace_bien_y_los_elementos_comparados_son_correctos();
	la_cantidad_de_elementos_es_correcta_en_postorden();

	return pa2m_mostrar_reporte();
}