//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct StructuraMasina
//{
//	int id;
//	int nrUsi;
//	float pret;
//	char* model;
//	char* numeSofer;
//	unsigned char serie;
//};
//typedef struct StructuraMasina Masina;
//
//struct Nod
//{
//	Masina info;
//	struct Nod* right;
//	struct Nod* left;
//};
//typedef struct Nod Nod;
//
//Masina citireMasinaDinFisier(FILE* file)
//{
//	char buffer[100];
//	char sep[3] = ",\n";
//
//	Masina m;
//
//	fgets(buffer, 100, file);
//	char* aux;
//
//	m.id = atoi(strtok(buffer, sep));
//	m.nrUsi = atoi(strtok(NULL, sep));
//	m.pret = atof(strtok(NULL, sep));
//
//	aux = strtok(NULL, sep);
//	m.model = malloc(strlen(aux) + 1);
//	strcpy(m.model, aux);
//
//	aux = strtok(NULL, sep);
//	m.numeSofer = malloc(strlen(aux) + 1);
//	strcpy(m.numeSofer, aux);
//
//	m.serie = strtok(NULL, sep)[0];
//
//	return m;
//}
//
//void afisareMasina(Masina masina)
//{
//	printf("Id: %d\n", masina.id);
//	printf("Nr. usi : %d\n", masina.nrUsi);
//	printf("Pret: %.2f\n", masina.pret);
//	printf("Model: %s\n", masina.model);
//	printf("Nume sofer: %s\n", masina.numeSofer);
//	printf("Serie: %c\n\n", masina.serie);
//}
//
//void adaugaMasinaInArbore(Nod** nod, Masina masinaNoua)
//{
//	if ((*nod) != NULL)
//	{
//		if (masinaNoua.id > (*nod)->info.id)
//		{
//			adaugaMasinaInArbore(&(*nod)->right, masinaNoua);
//		}
//		else if (masinaNoua.id < (*nod)->info.id)
//		{
//			adaugaMasinaInArbore(&(*nod)->left, masinaNoua);
//		}
//	}
//	else
//	{
//		(*nod) = (Nod*)malloc(sizeof(Nod));
//		(*nod)->info = masinaNoua;
//		(*nod)->right = NULL;
//		(*nod)->left = NULL;
//	}
//}
//
//Nod* citireArboreDeMasiniDinFisier(const char* numeFisier)
//{
//	FILE* f = fopen(numeFisier, "r");
//	Nod* nod = NULL;
//
//	while (!feof(f))
//	{
//		Masina m = citireMasinaDinFisier(f);
//		adaugaMasinaInArbore(&nod, m);
//	}
//	fclose(f);
//	return nod;
//}
//
//void afisarePreOrdineRSD(Nod* root)
//{
//	if (root != NULL)
//	{
//		afisareMasina(root->info);
//		afisarePreOrdineRSD(root->left);
//		afisarePreOrdineRSD(root->right);
//	}
//}
//
//void afisareInOrdineSRD(Nod* root)
//{
//	if (root != NULL)
//	{
//		afisareInOrdineSRD(root->left);
//		afisareMasina(root->info);
//		afisareInOrdineSRD(root->right);
//	}
//}
//
//void afisarePostOrdineSDR(Nod* root)
//{
//	if (root != NULL)
//	{
//		afisarePostOrdineSDR(root->left);
//		afisarePostOrdineSDR(root->right);
//		afisareMasina(root->info);
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
//int calculeazaInaltimeArbore(Nod* root)
//{
//	int inaltimeStanga = 0;
//	int inaltimeDreapta = 0;
//	int inaltime = 0;
//	if (root != NULL)
//	{
//		inaltimeStanga = calculeazaInaltimeArbore(root->left);
//		inaltimeDreapta = calculeazaInaltimeArbore(root->right);
//		inaltime = 1 + ((inaltimeStanga > inaltimeDreapta) ? inaltimeStanga : inaltimeDreapta);
//	}
//
//	return inaltime;
//}
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
//void dezalocareArboreDeMasini(Nod** root)
//{
//	if (root != NULL && (*root) != NULL)
//	{
//		dezalocareArboreDeMasini(&(*root)->left);
//		dezalocareArboreDeMasini(&(*root)->right);
//		free((*root)->info.numeSofer);
//		free((*root)->info.model);
//		free((*root));
//		*root = NULL;
//	}
//}
//
//int main()
//{
//	Nod* root = citireArboreDeMasiniDinFisier("masini.txt");
//	afisareInOrdineSRD(root);
//	afisarePreOrdineRSD(root);
//	afisarePostOrdineSDR(root);
//	puts("Masina cu id 1 este");
//	afisareMasina(getMasinaByID(root, 1));
//	printf("Sunt %d noduri\n", calculeazaNrNoduri(root));
//	printf("Sunt %d nivele\n", calculeazaInaltimeArbore(root));
//	printf("Pretul total este de %d u.m.\n", calculeazaPretTotal(root));
//	printf("Ionescu are masini in valoare de %.2f u.m.\n", calculeazaPretulMasinilorUnuiSofer(root, "Ionescu"));
//	dezalocareArboreDeMasini(&root);
//}