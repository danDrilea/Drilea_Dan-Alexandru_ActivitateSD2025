//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//struct StructuraMasina {
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	unsigned char serie;
//};
//typedef struct StructuraMasina Masina;
//
//struct nod {
//	Masina info;
//	struct nod* left;
//	struct nod* right;
//};
//typedef struct nod Nod;
//
//Masina citireMasinaDinFisier(FILE* file) {
//	char buffer[100];
//	char sep[3] = ",\n";
//	fgets(buffer, 100, file);
//	char* aux;
//	Masina m1;
//	aux = strtok(buffer, sep);
//	m1.id = atoi(aux);
//	m1.nrUsi = atoi(strtok(NULL, sep));
//	m1.pret = atof(strtok(NULL, sep));
//	aux = strtok(NULL, sep);
//	m1.model = malloc(strlen(aux) + 1);
//	strcpy_s(m1.model, strlen(aux) + 1, aux);
//
//	aux = strtok(NULL, sep);
//	m1.numeSofer = malloc(strlen(aux) + 1);
//	strcpy_s(m1.numeSofer, strlen(aux) + 1, aux);
//
//	m1.serie = *strtok(NULL, sep);
//	return m1;
//}
//
//void afisareMasina(Masina masina) {
//	printf("Id: %d\n", masina.id);
//	printf("Nr. usi : %d\n", masina.nrUsi);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n\n", masina.serie);
//}
//
//int calculeazaInaltimeArbore(Nod* root)
//{
//	if (root == NULL)
//		return 0;
//
//	int inaltimeStanga = calculeazaInaltimeArbore(root->left);
//	int inaltimeDreapta = calculeazaInaltimeArbore(root->right);
//	return 1 + ((inaltimeStanga > inaltimeDreapta) ? inaltimeStanga : inaltimeDreapta);
//}
//
//int calculeazaGE(Nod* root)
//{
//	return calculeazaInaltimeArbore(root->left) - calculeazaInaltimeArbore(root->right);
//}
//
//void rotireStanga(Nod** root)
//{
//	Nod* aux = (*root)->right;
//	(*root)->right = aux->left;
//	aux->left = (*root);
//	(*root) = aux;
//}
//
//void rotireDreapta(Nod** root)
//{
//	Nod* aux = (*root)->left;
//	(*root)->left = aux->right;
//	aux->right = (*root);
//	(*root) = aux;
//}
//
//void adaugaMasinaInArboreEchilibrat(Nod** root, Masina masinaNoua) {
//	if ((*root) != NULL)
//	{
//		if ((*root)->info.id < masinaNoua.id)
//		{
//			adaugaMasinaInArboreEchilibrat(&((*root)->right), masinaNoua);
//		}
//		else if ((*root)->info.id > masinaNoua.id)
//		{
//			adaugaMasinaInArboreEchilibrat(&((*root)->left), masinaNoua);
//		}
//		int gradEchilibru = calculeazaGE(*root);
//		if (gradEchilibru == 2)
//		{
//			if (calculeazaGE((*root)->left) == 1)
//			{
//				rotireDreapta(root);
//			}
//			else
//			{
//				rotireStanga(&((*root)->left));
//				rotireDreapta(root);
//			}
//		}
//		else if (gradEchilibru == -2)
//		{
//			if (calculeazaGE((*root)->right) == 1)
//			{
//				rotireDreapta(&((*root)->right));
//			}
//			rotireStanga(root);
//		}
//	}
//	else
//	{
//		(*root) = (Nod*)malloc(sizeof(Nod));
//		(*root)->info = masinaNoua;
//		(*root)->left = NULL;
//		(*root)->right = NULL;
//	}
//}
//
//Nod* citireArboreDeMasiniDinFisier(const char* numeFisier) {
//	FILE* f = fopen(numeFisier, "r");
//	Masina m;
//	Nod* root = NULL;
//
//	while (!feof(f))
//	{
//		m = citireMasinaDinFisier(f);
//		adaugaMasinaInArboreEchilibrat(&root, m);
//	}
//	fclose(f);
//	return root;
//}
//
//void afisareMasiniDinArboreRSD(Nod* root)
//{
//	if (root != NULL)
//	{
//		afisareMasina(root->info);
//		afisareMasiniDinArboreRSD(root->left);
//		afisareMasiniDinArboreRSD(root->right);
//	}
//}
//
//void afisareMasiniDinArboreSRD(Nod* root)
//{
//	if (root != NULL)
//	{
//		afisareMasiniDinArboreSRD(root->left);
//		afisareMasina(root->info);
//		afisareMasiniDinArboreSRD(root->right);
//	}
//}
//
//void afisareMasiniDinArboreSDR(Nod* root)
//{
//	if (root != NULL)
//	{
//		afisareMasiniDinArboreSDR(root->left);
//		afisareMasiniDinArboreSDR(root->right);
//		afisareMasina(root->info);
//	}
//}
//void dezalocareArboreDeMasini(Nod** root)
//{
//	if (*(root) != NULL)
//	{
//		dezalocareArboreDeMasini(&((*root)->left));
//		dezalocareArboreDeMasini(&((*root)->right));
//		free((*root)->info.model);
//		free((*root)->info.numeSofer);
//		free((*root));
//		(*root) = NULL;
//	}
//}
//
//Masina getMasinaByID(Nod* root, int id)
//{
//	Masina m;
//	m.id = -1;
//
//	if (root != NULL)
//	{
//		if (id < root->info.id)
//		{
//			return getMasinaByID(root->left, id);
//		}
//		else if (id > root->info.id)
//		{
//			return getMasinaByID(root->right, id);
//		}
//		else
//		{
//			return root->info;
//		}
//	}
//	return m;
//}
//
//int calculeazaNrNoduri(Nod* root)
//{
//	int NodeCount = 0;
//	if (root != NULL)
//	{
//		NodeCount += calculeazaNrNoduri(root->left);
//		NodeCount += calculeazaNrNoduri(root->right);
//		NodeCount++;
//	}
//	return NodeCount;
//}
//
//
//int calculeazaPretTotal(Nod* root)
//{
//	float pretTotal = 0;
//	if (root != NULL)
//	{
//		pretTotal += root->info.pret;
//		pretTotal += calculeazaPretTotal(root->left);
//		pretTotal += calculeazaPretTotal(root->right);
//	}
//	return pretTotal;
//}
//
//float calculeazaPretulMasinilorUnuiSofer(Nod* root, const char* numeSofer)
//{
//	float pretTotal = 0;
//	if (root != NULL)
//	{
//		if (strcmp(root->info.numeSofer, numeSofer) == 0)
//		{
//			pretTotal += root->info.pret;
//		}
//		pretTotal += calculeazaPretulMasinilorUnuiSofer(root->left, numeSofer);
//		pretTotal += calculeazaPretulMasinilorUnuiSofer(root->right, numeSofer);
//	}
//	return pretTotal;
//}
//
//int main()
//{
//	Nod* root = citireArboreDeMasiniDinFisier("masini.txt");
//
//	afisareMasiniDinArboreRSD(root);
//	afisareMasiniDinArboreSRD(root);
//	afisareMasiniDinArboreSDR(root);
//	puts("Masina cu id 1 este");
//	afisareMasina(getMasinaByID(root, 1));
//	printf("Sunt %d noduri\n", calculeazaNrNoduri(root));
//	printf("Sunt %d nivele\n", calculeazaInaltimeArbore(root));
//	printf("Pretul total este de %d u.m.\n", calculeazaPretTotal(root));
//	printf("Ionescu are masini in valoare de %.2f u.m.\n", calculeazaPretulMasinilorUnuiSofer(root, "Ionescu"));
//	dezalocareArboreDeMasini(&root);
//}