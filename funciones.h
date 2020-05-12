void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);   //funcion gotoxy para cambiar la ubicacion del puntero e imprimir
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);
  }
  
void agregar(){
	int opc=0;
	fflush(stdin);
	printf("Desea Recuperar lista? 1-Si 2.-No: ");
	scanf("%d",&opc);
	if(opc==1){
		sacardelista();
		printf("Lista recuperada exitosamente....\n");
		printf("Presione Enter para regresar al menu....");
		getch();
		if(usuario.admin==true){
			menuadmin();
			
		}else{
			menusr();
		}
		
	}else{
		system("cls");
		struct registro *nuevo;
		struct registro *aux; 
		nuevo=(struct registro*) malloc(sizeof(struct registro));
		if (nuevo==NULL) printf( "No hay memoria disponible!\n");
	    fflush(stdin);
	    printf("Nombre del producto: "); 
	    scanf("%s",nuevo->nombre);
	    fflush(stdin);
		nuevo->id= 10000+rand()%89999;
		printf("Id del producto: %d\n",nuevo->id);
		printf("Ingresa la fecha de entrada\nDia: ");
		scanf("%d",&nuevo->entrada.di);
		printf("Mes: ");
		scanf("%d",&nuevo->entrada.me);
		printf("Año: ");
		scanf("%d",&nuevo->entrada.an);
		printf("Ingresa la fecha de caducidad\nDia: ");
		scanf("%d",&nuevo->caducidad.di);
		printf("Mes: ");
		scanf("%d",&nuevo->caducidad.me);
		printf("Año: ");
		scanf("%d",&nuevo->caducidad.an);
	    printf("Cantidad en existencia: "); 
	    scanf("%d",&nuevo->exis);
	    printf("Estado del Producto del producto: "); 
	    scanf("%d",&nuevo->estado);
	    
	      
	   if(primero==NULL){
	   	
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = nuevo;
		}else{
			
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
		}
		largo++;
	}
}

void listadoid(){
	char nombre[15];
	system("cls");
	printf("Id\tNombre\tCantidad\tFecha de caducidad\tFecha de Entrada\tEstado");
	struct registro *p,*j,*auxiliar;
	p=primero;
	while(p!=NULL){
		j=p->siguiente;
		while(j != NULL){
			if(p->id>=j->id){
				int anio=j->caducidad.an;
				int id=j->id;
				int ex=j->exis;
				int es=j->estado;
				int mes=j->caducidad.me;
				int dia=j->caducidad.di;
				strcpy(nombre,j->nombre);
				int eanio=j->entrada.an;
				int emes=j->entrada.me;
				int edia=j->entrada.di;
				
				j->id=p->id;
				strcpy(j->nombre,p->nombre);
				j->caducidad.an=p->caducidad.an;
				j->caducidad.di=p->caducidad.di;
				j->caducidad.me=p->caducidad.me;
				j->entrada.an=p->entrada.an;
				j->entrada.me=p->entrada.me;
				j->entrada.di=p->entrada.di;
				j->exis=p->exis;
				
				p->id=id;
				p->exis=ex;
				p->estado=es;
				p->entrada.an=eanio;
				p->entrada.di=edia;
				p->entrada.me=emes;
				p->caducidad.me=mes;
				p->caducidad.di=dia;
				p->caducidad.an= anio;
				strcpy(p->nombre,nombre);
				
			}
			j=j->siguiente;
		}
		p=p->siguiente;
	}
	
	auxiliar=primero;
	while(auxiliar!=NULL){
		
		printf("\n%d",auxiliar->id);
		printf("\t%s",auxiliar->nombre);
		printf("\t%d\t\t",auxiliar->exis);
		printf("%d",auxiliar->caducidad.di);
		printf("/%d",auxiliar->caducidad.me);
		printf("/%d",auxiliar->caducidad.an);
		printf("\t\t%d",auxiliar->entrada.di);
		printf("/%d",auxiliar->entrada.me);
		printf("/%d",auxiliar->entrada.an);
		if(auxiliar->estado==1){
			printf("\t\tAlta\n");
		}else{
			printf("\t\tBaja\n");
		}
		
		auxiliar=auxiliar->siguiente;
		
	}
	
	reporte();
	printf("Presione cualquier tecla para continuar...");
	getch();
	
	
}
void listado_caducidad(){
	char nombre[15];
	system("cls");
	printf("Id\tNombre\tCantidad\tFecha de caducidad\tFecha de Entrada\tEstado");
	struct registro *p,*j,*auxiliar;
		p=primero;
	while(p!=NULL){
		j=p->siguiente;
		while(j != NULL){
			if(p->caducidad.an==j->caducidad.an){
				if(p->caducidad.me==j->caducidad.me){
					if(p->caducidad.di>j->caducidad.di){		
							int anio=j->caducidad.an;
							int id=j->id;
							int ex=j->exis;
							int es=j->estado;
							int mes=j->caducidad.me;
							int dia=j->caducidad.di;
							strcpy(nombre,j->nombre);
							int eanio=j->entrada.an;
							int emes=j->entrada.me;
							int edia=j->entrada.di;
									
							j->id=p->id;
							strcpy(j->nombre,p->nombre);
							j->caducidad.an=p->caducidad.an;
							j->caducidad.di=p->caducidad.di;
							j->caducidad.me=p->caducidad.me;
							j->entrada.an=p->entrada.an;
							j->entrada.me=p->entrada.me;
							j->entrada.di=p->entrada.di;
							j->exis=p->exis;
									
							p->id=id;
							p->exis=ex;
							p->estado=es;
							p->entrada.an=eanio;
							p->entrada.di=edia;
							p->entrada.me=emes;
							p->caducidad.me=mes;
							p->caducidad.di=dia;
							p->caducidad.an= anio;
							strcpy(p->nombre,nombre);
								
							
						
					}
					
				}else{
					if(p->caducidad.me>=j->caducidad.me){		
					int anio=j->caducidad.an;
					int id=j->id;
					int ex=j->exis;
					int es=j->estado;
					int mes=j->caducidad.me;
					int dia=j->caducidad.di;
					strcpy(nombre,j->nombre);
					int eanio=j->entrada.an;
					int emes=j->entrada.me;
					int edia=j->entrada.di;
							
					j->id=p->id;
					strcpy(j->nombre,p->nombre);
					j->caducidad.an=p->caducidad.an;
					j->caducidad.di=p->caducidad.di;
					j->caducidad.me=p->caducidad.me;
					j->entrada.an=p->entrada.an;
					j->entrada.me=p->entrada.me;
					j->entrada.di=p->entrada.di;
					j->exis=p->exis;
							
					p->id=id;
					p->exis=ex;
					p->estado=es;
					p->entrada.an=eanio;
					p->entrada.di=edia;
					p->entrada.me=emes;
					p->caducidad.me=mes;
					p->caducidad.di=dia;
					p->caducidad.an= anio;
					strcpy(p->nombre,nombre);		
					
					}		
				}
				
			}else{
				if(p->caducidad.an>=j->caducidad.an){		
					int anio=j->caducidad.an;
					int id=j->id;
					int ex=j->exis;
					int es=j->estado;
					int mes=j->caducidad.me;
					int dia=j->caducidad.di;
					strcpy(nombre,j->nombre);
					int eanio=j->entrada.an;
					int emes=j->entrada.me;
					int edia=j->entrada.di;
							
					j->id=p->id;
					strcpy(j->nombre,p->nombre);
					j->caducidad.an=p->caducidad.an;
					j->caducidad.di=p->caducidad.di;
					j->caducidad.me=p->caducidad.me;
					j->entrada.an=p->entrada.an;
					j->entrada.me=p->entrada.me;
					j->entrada.di=p->entrada.di;
					j->exis=p->exis;
							
					p->id=id;
					p->exis=ex;
					p->estado=es;
					p->entrada.an=eanio;
					p->entrada.di=edia;
					p->entrada.me=emes;
					p->caducidad.me=mes;
					p->caducidad.di=dia;
					p->caducidad.an= anio;
					strcpy(p->nombre,nombre);
						
					
				}
			}
			
			j=j->siguiente;
		}
			p=p->siguiente;
	}
	
	
	auxiliar=primero;
	while(auxiliar!=NULL){
		
		printf("\n%d",auxiliar->id);
		printf("\t%s",auxiliar->nombre);
		printf("\t%d\t\t",auxiliar->exis);
		printf("%d",auxiliar->caducidad.di);
		printf("/%d",auxiliar->caducidad.me);
		printf("/%d",auxiliar->caducidad.an);
		printf("\t\t%d",auxiliar->entrada.di);
		printf("/%d",auxiliar->entrada.me);
		printf("/%d",auxiliar->entrada.an);
		if(auxiliar->estado==1){
			printf("\t\tAlta\n");
		}else{
			printf("\t\tBaja\n");
		}
		
		auxiliar=auxiliar->siguiente;
		
	}
	reporte();
	printf("Presione cualquier tecla para continuar...");
	getch();
	
	
}

void sacardelista(){
	
	FILE *arch;
	struct registro *nuevo;
	struct registro *aux; 
	
	if(!(arch=fopen("Lista.xls","r"))){
		printf("Error al intentar abrir el archivo o no existe.../n");
		printf("Presione Enter para regresar al menu....");
		fclose(arch);
		getch();
		if(usuario.admin==true){
			menuadmin();
			
		}else{
			menusr();
		}
	}
	
	while(!feof(arch)){
	
		nuevo=(struct registro*) malloc(sizeof(struct registro));
		if (nuevo==NULL) printf( "No hay memoria disponible!\n");
		fscanf(arch,"%d\t",&nuevo->id);
		fscanf(arch,"%s\t",nuevo->nombre);
		fscanf(arch,"%d\t",&nuevo->id);
		fscanf(arch,"%d\t",&nuevo->entrada.di);
		fscanf(arch,"%d\t",&nuevo->entrada.me);
		fscanf(arch,"%d\t",&nuevo->entrada.an);
		fscanf(arch,"%d\t",&nuevo->caducidad.di);
		fscanf(arch,"%d\t",&nuevo->caducidad.me);
		fscanf(arch,"%d\t",&nuevo->caducidad.an);
		fscanf(arch,"%d\t",&nuevo->exis);
		fscanf(arch,"%d\n",&nuevo->estado);
		
		nuevo->siguiente = NULL; 
    
        
	   if(primero==NULL){
	   	
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = nuevo;
		}else{
			
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
		}
		largo++;
	}
	fclose(arch);
	
}
void reporte_caducidad(){
	struct registro *auxiliar;
	FILE *arch;
	remove("ListaCaducidad.xls");
	
	if(!(arch=fopen("ListaCaducidad.xls","a+"))){
		printf("Error al intentar abrir el archivo o no existe...\n");
		printf("Presione Enter para regresar al menu....");
		fclose(arch);
		getch();
		if(usuario.admin==true){
			menuadmin();
			
		}else{
			menusr();
		}
	}
	char nombre[15];
	struct registro *p,*j;
	p=primero;
	while(p!=NULL){
		j=p->siguiente;
		while(j != NULL){
			if(p->caducidad.an==j->caducidad.an){
				if(p->caducidad.me==j->caducidad.me){
					if(p->caducidad.di>j->caducidad.di){		
							int anio=j->caducidad.an;
							int id=j->id;
							int ex=j->exis;
							int es=j->estado;
							int mes=j->caducidad.me;
							int dia=j->caducidad.di;
							strcpy(nombre,j->nombre);
							int eanio=j->entrada.an;
							int emes=j->entrada.me;
							int edia=j->entrada.di;
									
							j->id=p->id;
							strcpy(j->nombre,p->nombre);
							j->caducidad.an=p->caducidad.an;
							j->caducidad.di=p->caducidad.di;
							j->caducidad.me=p->caducidad.me;
							j->entrada.an=p->entrada.an;
							j->entrada.me=p->entrada.me;
							j->entrada.di=p->entrada.di;
							j->exis=p->exis;
									
							p->id=id;
							p->exis=ex;
							p->estado=es;
							p->entrada.an=eanio;
							p->entrada.di=edia;
							p->entrada.me=emes;
							p->caducidad.me=mes;
							p->caducidad.di=dia;
							p->caducidad.an= anio;
							strcpy(p->nombre,nombre);
								
							
						
					}
					
				}else{
					if(p->caducidad.me>=j->caducidad.me){		
					int anio=j->caducidad.an;
					int id=j->id;
					int ex=j->exis;
					int es=j->estado;
					int mes=j->caducidad.me;
					int dia=j->caducidad.di;
					strcpy(nombre,j->nombre);
					int eanio=j->entrada.an;
					int emes=j->entrada.me;
					int edia=j->entrada.di;
							
					j->id=p->id;
					strcpy(j->nombre,p->nombre);
					j->caducidad.an=p->caducidad.an;
					j->caducidad.di=p->caducidad.di;
					j->caducidad.me=p->caducidad.me;
					j->entrada.an=p->entrada.an;
					j->entrada.me=p->entrada.me;
					j->entrada.di=p->entrada.di;
					j->exis=p->exis;
							
					p->id=id;
					p->exis=ex;
					p->estado=es;
					p->entrada.an=eanio;
					p->entrada.di=edia;
					p->entrada.me=emes;
					p->caducidad.me=mes;
					p->caducidad.di=dia;
					p->caducidad.an= anio;
					strcpy(p->nombre,nombre);		
					
					}		
				}
				
			}else{
				if(p->caducidad.an>=j->caducidad.an){		
					int anio=j->caducidad.an;
					int id=j->id;
					int ex=j->exis;
					int es=j->estado;
					int mes=j->caducidad.me;
					int dia=j->caducidad.di;
					strcpy(nombre,j->nombre);
					int eanio=j->entrada.an;
					int emes=j->entrada.me;
					int edia=j->entrada.di;
							
					j->id=p->id;
					strcpy(j->nombre,p->nombre);
					j->caducidad.an=p->caducidad.an;
					j->caducidad.di=p->caducidad.di;
					j->caducidad.me=p->caducidad.me;
					j->entrada.an=p->entrada.an;
					j->entrada.me=p->entrada.me;
					j->entrada.di=p->entrada.di;
					j->exis=p->exis;
							
					p->id=id;
					p->exis=ex;
					p->estado=es;
					p->entrada.an=eanio;
					p->entrada.di=edia;
					p->entrada.me=emes;
					p->caducidad.me=mes;
					p->caducidad.di=dia;
					p->caducidad.an= anio;
					strcpy(p->nombre,nombre);
						
					
				}
			}
			
			j=j->siguiente;
		}
			p=p->siguiente;
	}
	
	

	auxiliar=primero;
	
	while(auxiliar!=NULL){
		fprintf(arch,"%d\t",auxiliar->id);
		fprintf(arch,"%s\t",auxiliar->nombre);
		fprintf(arch,"%d\t",auxiliar->id);
		fprintf(arch,"%d\t",auxiliar->entrada.di);
		fprintf(arch,"%d\t",auxiliar->entrada.me);
		fprintf(arch,"%d\t",auxiliar->entrada.an);
		fprintf(arch,"%d\t",auxiliar->caducidad.di);
		fprintf(arch,"%d\t",auxiliar->caducidad.me);
		fprintf(arch,"%d\t",auxiliar->caducidad.an);
		fprintf(arch,"%d\t",auxiliar->exis);
		fprintf(arch,"%d\n",auxiliar->estado);
		largo++;
		auxiliar=auxiliar->siguiente;
	}
	fclose(arch);
	printf("Reporte hecho exitosamente...\n");
	printf("Presione enter para regresar al menu...");
	getch();
	
	if(usuario.admin==true){
		menuadmin();
			
	}else{
		menusr();
	}
	
	
}
void reporte(){
	struct registro *auxiliar;
	FILE *arch;
	remove("Lista.xls");
	
	if(!(arch=fopen("Lista.xls","a+"))){
		printf("Error al intentar abrir el archivo o no existe.../n");
		printf("Presione Enter para regresar al menu....");
		fclose(arch);
		getch();
		if(usuario.admin==true){
			menuadmin();
			
		}else{
			menusr();
		}
	}
	auxiliar=primero;
	
	while(auxiliar!=NULL){
		fprintf(arch,"%d\t",auxiliar->id);
		fprintf(arch,"%s\t",auxiliar->nombre);
		fprintf(arch,"%d\t",auxiliar->id);
		fprintf(arch,"%d\t",auxiliar->entrada.di);
		fprintf(arch,"%d\t",auxiliar->entrada.me);
		fprintf(arch,"%d\t",auxiliar->entrada.an);
		fprintf(arch,"%d\t",auxiliar->caducidad.di);
		fprintf(arch,"%d\t",auxiliar->caducidad.me);
		fprintf(arch,"%d\t",auxiliar->caducidad.an);
		fprintf(arch,"%d\t",auxiliar->exis);
		fprintf(arch,"%d\n",auxiliar->estado);
		largo++;
		auxiliar=auxiliar->siguiente;
	}
	fclose(arch);
	printf("\nLista actualizada exitosamente...\n");
	printf("Presione enter para regresar al menu...");
	getch();
	
	if(usuario.admin==true){
		menuadmin();
			
	}else{
		menusr();
	}
	
	
}


void reporte_existencia(){
	struct registro *auxiliar;
	FILE *arch;
	remove("ListaExistencia.xls");
	
	if(!(arch=fopen("ListaExistencia.xls","a+"))){
		printf("Error al intentar abrir el archivo o no existe.../n");
		printf("Presione Enter para regresar al menu....");
		fclose(arch);
		getch();
		if(usuario.admin==true){
			menuadmin();
			
		}else{
			menusr();
		}
	}
	char nombre[15];
	struct registro *p,*j;
	p=primero;
	while(p!=NULL){
		j=p->siguiente;
		while(j != NULL){
			if(p->exis<=j->exis){
				int anio=j->caducidad.an;
				int id=j->id;
				int ex=j->exis;
				int es=j->estado;
				int mes=j->caducidad.me;
				int dia=j->caducidad.di;
				strcpy(nombre,j->nombre);
				int eanio=j->entrada.an;
				int emes=j->entrada.me;
				int edia=j->entrada.di;
				
				j->id=p->id;
				strcpy(j->nombre,p->nombre);
				j->caducidad.an=p->caducidad.an;
				j->caducidad.di=p->caducidad.di;
				j->caducidad.me=p->caducidad.me;
				j->entrada.an=p->entrada.an;
				j->entrada.me=p->entrada.me;
				j->entrada.di=p->entrada.di;
				j->exis=p->exis;
				
				p->id=id;
				p->exis=ex;
				p->estado=es;
				p->entrada.an=eanio;
				p->entrada.di=edia;
				p->entrada.me=emes;
				p->caducidad.me=mes;
				p->caducidad.di=dia;
				p->caducidad.an= anio;
				strcpy(p->nombre,nombre);
				
			}
			j=j->siguiente;
		}
		p=p->siguiente;
	}
	

	auxiliar=primero;
	
	while(auxiliar!=NULL){
		fprintf(arch,"%d\t",auxiliar->id);
		fprintf(arch,"%s\t",auxiliar->nombre);
		fprintf(arch,"%d\t",auxiliar->id);
		fprintf(arch,"%d\t",auxiliar->entrada.di);
		fprintf(arch,"%d\t",auxiliar->entrada.me);
		fprintf(arch,"%d\t",auxiliar->entrada.an);
		fprintf(arch,"%d\t",auxiliar->caducidad.di);
		fprintf(arch,"%d\t",auxiliar->caducidad.me);
		fprintf(arch,"%d\t",auxiliar->caducidad.an);
		fprintf(arch,"%d\t",auxiliar->exis);
		fprintf(arch,"%d\n",auxiliar->estado);
		largo++;
		auxiliar=auxiliar->siguiente;
	}
	fclose(arch);
	printf("\nReporte hecho exitosamente...\n");
	printf("Presione enter para regresar al menu...");
	getch();
	
	if(usuario.admin==true){
		menuadmin();
			
	}else{
		menusr();
	}
	
	
}

void eliminar(){
	struct registro *anterior=NULL;
	struct registro *aux_borrar;
	int idcomp;
	int i;
	printf("\n\tIngrese el Id del producto: ");
	scanf("%d",&idcomp);
	printf("\n\t id:%d",idcomp);
	getch();
	aux_borrar=primero;
	while((aux_borrar!=NULL) && (aux_borrar->id != idcomp)){
		anterior=aux_borrar;
		aux_borrar=aux_borrar->siguiente;
	}
	
	if(aux_borrar==NULL){
		printf("\nEl producto no se encontro presione una tecla para regresar al menu");
	}else{
		if(anterior==NULL){
			primero=primero->siguiente;
			delete aux_borrar;
			printf("\nProducto eliminado correctamente");
		}else{
			anterior->siguiente=aux_borrar->siguiente;
			delete aux_borrar;
			printf("\nProducto eliminado correctamente");
		}
	}
	reporte();
	getch();
}

void listado_entrada(){
	char nombre[15];
	system("cls");
	printf("Id\tNombre\tCantidad\tFecha de caducidad\tFecha de Entrada\tEstado");
	struct registro *p,*j,*auxiliar;
	p=primero;
	while(p!=NULL){
		j=p->siguiente;
		while(j != NULL){
			if(p->entrada.an==j->entrada.an){
				if(p->entrada.me==j->entrada.me){
					if(p->entrada.di>j->entrada.di){		
							int anio=j->caducidad.an;
							int id=j->id;
							int ex=j->exis;
							int es=j->estado;
							int mes=j->caducidad.me;
							int dia=j->caducidad.di;
							strcpy(nombre,j->nombre);
							int eanio=j->entrada.an;
							int emes=j->entrada.me;
							int edia=j->entrada.di;
									
							j->id=p->id;
							strcpy(j->nombre,p->nombre);
							j->caducidad.an=p->caducidad.an;
							j->caducidad.di=p->caducidad.di;
							j->caducidad.me=p->caducidad.me;
							j->entrada.an=p->entrada.an;
							j->entrada.me=p->entrada.me;
							j->entrada.di=p->entrada.di;
							j->exis=p->exis;
									
							p->id=id;
							p->exis=ex;
							p->estado=es;
							p->entrada.an=eanio;
							p->entrada.di=edia;
							p->entrada.me=emes;
							p->caducidad.me=mes;
							p->caducidad.di=dia;
							p->caducidad.an= anio;
							strcpy(p->nombre,nombre);
								
							
						
					}
					
				}else{
					if(p->entrada.me>=j->entrada.me){		
					int anio=j->caducidad.an;
					int id=j->id;
					int ex=j->exis;
					int es=j->estado;
					int mes=j->caducidad.me;
					int dia=j->caducidad.di;
					strcpy(nombre,j->nombre);
					int eanio=j->entrada.an;
					int emes=j->entrada.me;
					int edia=j->entrada.di;
							
					j->id=p->id;
					strcpy(j->nombre,p->nombre);
					j->caducidad.an=p->caducidad.an;
					j->caducidad.di=p->caducidad.di;
					j->caducidad.me=p->caducidad.me;
					j->entrada.an=p->entrada.an;
					j->entrada.me=p->entrada.me;
					j->entrada.di=p->entrada.di;
					j->exis=p->exis;
							
					p->id=id;
					p->exis=ex;
					p->estado=es;
					p->entrada.an=eanio;
					p->entrada.di=edia;
					p->entrada.me=emes;
					p->caducidad.me=mes;
					p->caducidad.di=dia;
					p->caducidad.an= anio;
					strcpy(p->nombre,nombre);		
					
					}		
				}
				
			}else{
				if(p->entrada.an>=j->entrada.an){		
					int anio=j->caducidad.an;
					int id=j->id;
					int ex=j->exis;
					int es=j->estado;
					int mes=j->caducidad.me;
					int dia=j->caducidad.di;
					strcpy(nombre,j->nombre);
					int eanio=j->entrada.an;
					int emes=j->entrada.me;
					int edia=j->entrada.di;
							
					j->id=p->id;
					strcpy(j->nombre,p->nombre);
					j->caducidad.an=p->caducidad.an;
					j->caducidad.di=p->caducidad.di;
					j->caducidad.me=p->caducidad.me;
					j->entrada.an=p->entrada.an;
					j->entrada.me=p->entrada.me;
					j->entrada.di=p->entrada.di;
					j->exis=p->exis;
							
					p->id=id;
					p->exis=ex;
					p->estado=es;
					p->entrada.an=eanio;
					p->entrada.di=edia;
					p->entrada.me=emes;
					p->caducidad.me=mes;
					p->caducidad.di=dia;
					p->caducidad.an= anio;
					strcpy(p->nombre,nombre);
						
					
				}
			}
			
			j=j->siguiente;
		}
			p=p->siguiente;
	}
	
	auxiliar=primero;
	while(auxiliar!=NULL){
		
		printf("\n%d",auxiliar->id);
		printf("\t%s",auxiliar->nombre);
		printf("\t%d\t\t",auxiliar->exis);
		printf("%d",auxiliar->caducidad.di);
		printf("/%d",auxiliar->caducidad.me);
		printf("/%d",auxiliar->caducidad.an);
		printf("\t\t%d",auxiliar->entrada.di);
		printf("/%d",auxiliar->entrada.me);
		printf("/%d",auxiliar->entrada.an);
		if(auxiliar->estado==1){
			printf("\t\tAlta\n");
		}else{
			printf("\t\tBaja\n");
		}
		
		auxiliar=auxiliar->siguiente;
		
	}
	printf("\nPresione cualquier tecla para continuar...");
	getch();
	
	
}

void modificar(){
	struct registro *auxiliar;
	int idcomp=0;
	printf("Ingrese el id del producto a modificar: ");
	scanf("%d",&idcomp);
	
	auxiliar=primero;
	if(auxiliar!=NULL){
		if(idcomp==auxiliar->id){
			printf("\nNombre del producto: %s",auxiliar->nombre);
    		printf("Cantidad en existencia: "); 
    		scanf("%d",&auxiliar->exis);
    		printf("Estado del Producto del producto: "); 
   			scanf("%d",&auxiliar->estado);
			
		}
		auxiliar=auxiliar->siguiente;
	}
	reporte();
	printf("\nPresione una tecla para continuar....");
	getch();
}

void menuadmin(){
	bool bandera;
	bandera=false;
	while(!bandera){
		system("cls");
		printf("\t\t\tMenu de Administrador\n\nEliga la opcion que desea seleccionar:\n\n0.-Modificar Producto\n\n1.-Agregar Producto\n\n2.-Dar de baja productos\n\n3.-Listado de productos por identificador.\n\n4.-Listado de productos por fecha de caducacidad.\n\n5.-Listado de productos por fecha de entrada.\n\n6.-Reporte de proximos productos a caducar.\n\n7.-Reporte de productos proximos a terminarse.\n\n8.-Salir.\n:");
		usuario.opc=validaEntero();
		switch(usuario.opc){
			case 0:
				modificar();
			break;
			case 1:
				agregar();
			break;
			case 2:
				eliminar();
			break;
			case 3:
				listadoid();
			break;
			case 4:
				listado_caducidad();
			break;
			case 5:
				listado_entrada();
			break;
			case 6:
				reporte_existencia();
			break;
			case 7:
				reporte_caducidad();
			break;
			case 8:
				bandera=true;
				exit(1);
			break;
			default:
			printf("Opcion no valida!");
			break;
			
		}
	}
}

void menusr(){
	bool bandera=false;
	sacardelista();
	while(!bandera){
		system("cls");
		printf("\t\t\tMenu de Usuario\n\nEliga la opcion que desea seleccionar:\n\n1.-Listado de productos por identificador\n\n2.-Listado de productos por fecha de caducacidad.\n\n3.-Listado de productos por fecha de entrada.\n\n4.-Reporte de proximos productos a caducar.\n\n5.-Reporte de productos proximos a terminarse.\n\n6.-Salir\n:");
		usuario.opc=validaEntero();
		switch(usuario.opc){
			case 1:
				listadoid();
			break;
			case 2:
				listado_caducidad();
			break;
			case 3:
				listado_entrada();
			break;
			case 4:
				reporte_caducidad();
			break;
			case 5:
				reporte_existencia();
			break;
			case 6:
				bandera=true;
				exit(1);
			break;
			default:
			printf("Opcion no valida!");
			break;
			
		}
	}
}

void login(){
	bool bandera=false;
	usuario.admin=false;
	int intento=0;
	while(!bandera){
		if(intento>=5){
			system("cls");
			printf("Se ah excedido el limite de intentos. Terminando Programa...");
			exit(1);
		}
		system("cls");
		gotoxy(45,25);
		printf("%c",201);
		gotoxy(75,25);
		printf("%c",187);
		gotoxy(45,40);
		printf("%c",200);
		gotoxy(75,40);
		printf("%c",188);
			if(intento>0){
			gotoxy(45,21);
			printf("Solo tienes 5 intentos, de lo contrario se terminarar el programa por seguridad.");
			gotoxy(45,22);
			printf("Numero de intentos: %d",intento);
		}
		
		for(int i=0;i<29;i++){
			gotoxy(46+i,25);
			printf("%c",205);
			gotoxy(46+i,40);
			printf("%c",205);
			for(int j=0;j<14;j++){
				gotoxy(45,26+j);
				printf("%c",186);
				gotoxy(75,26+j);
				printf("%c",186);
			}
		}
		gotoxy(50,27);
		printf("-------Login-------");
		gotoxy(48,30);
		printf("Usuario:");
		gotoxy(48,34);
		printf("Contrase%ca:",164);
		gotoxy(56,30);
		scanf("%s",usuario.usr);
		gotoxy(56,30);
		gotoxy(60,34);
		scanf("%s",usuario.psw);
		gotoxy(60,34);
		intento++;
		
		if(strcmp(usuario.usr,"admin")==0){
				if(strcmp(usuario.psw,"root")==0){
					gotoxy(47,47);
					printf("Acceso Concedido!");
					gotoxy(47,48);
					printf("Haz ingresado como Administrador!");
					usuario.admin=true;
					bandera=true;
					getch();
					menuadmin();
				}
		}
		
		if(strcmp(usuario.usr,"usuario")==0){
			if(strcmp(usuario.psw,"pswd")==0){
				gotoxy(47,47);
				printf("Acceso Concedido!");
				gotoxy(47,48);
				printf("Haz ingresado como operario!");
				usuario.admin=false;
				bandera=true;
				getch();
				menusr();
			}
		}
		
		if(!bandera){
			gotoxy(47,48);
			printf("Acceso Denegado!");
			getch();
			fflush(stdin);
		}
	
	}
	
}


void portada(){
	int a=0, s=0;
	for(a=0;a<REN;a++)
	{
		for(s=0;s<COL;s++)								//se imprime la portada que se almaceno en un arreglo y con la funcion setconsole cambia a los colores 
		{												//requeridos
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),imagen[a][s]);
			printf("%c",219);
		}
		printf("\n");
		Sleep(15);
	}
	
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
	gotoxy(120,30);
	printf("    SMART STORAGE MANAGEMENT MODULE\n");
	gotoxy(120,32);
	printf("Elavorado por :");
	gotoxy(120,34);
	printf(" Gabriel Covarrubias Gonzalez 180818\n");
	gotoxy(120,36);
	printf(" Diego Armando Garcia Guillen 181259\n");
	gotoxy(120,38);
	printf("Universidad Politecnica de San Luis Potosi\n");
	gotoxy(120,40);
	printf("Programacion II\n");
	gotoxy(120,42);
	printf("Press Any Key to continue...");
	getch();
	
}

