#ifndef VERTEX_H
#define VERTEX_H

typedef struct _vertex Vertex;

Vertex *Vertex_create(void *data);

void Vertex_destroy(Vertex **vertex_ref);

void *Vertex_get_data(Vertex *vertex);

void Vertex_set_data(Vertex *vertex, void *data);

long Vertex_get_valency(Vertex *vertex);

void Vertex_set_valency(Vertex *vertex, long new_valency);

void Vertex_valency_up(Vertex *vertex);

void Vertex_valency_down(Vertex *vertex);

#endif