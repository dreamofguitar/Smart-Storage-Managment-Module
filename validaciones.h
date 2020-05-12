
float validaFlotante (){
	char cadena[6]="";
	bool bandera = true;
	float flotante=0;
	int cont=0;
	
	while(bandera){
		//printf("flotante: ");
		scanf("%[^\n]",cadena);
		fflush(stdin);				
		if(strlen(cadena)>5){
			continue;
		}else{
			for(int i = 0; i<strlen(cadena); i++){				
				if( !(isdigit(cadena[i])) ){
					if(cadena[i]=='.' && cont==0){
						cont++;
					}else{
						cont=0;
						break;
					}
				}
				if (i == (strlen(cadena)-1)){
					flotante = atof(cadena);								
					bandera=false;
				}
			}
		}				
	} 
	return flotante; 
}

int validaEntero (){
	char cadena[6]="";
	bool bandera = true;
	int entero=0;
	
	while(bandera){
		//printf("Entero: ");
		scanf("%[^\n]",cadena);
		fflush(stdin);				
		if(strlen(cadena)>8){
			continue;
		}else{
			for(int i = 0; i<strlen(cadena); i++){
				if(isdigit(cadena[i])){
					if (i== (strlen(cadena)-1)){
						entero = atoi(cadena);									
						bandera=false;
					}
				}else{
					break;
				}
			}
		}				
	}

	return entero; 
}

void validaCadena(char cadena[]){
	bool bandera = true;
	while(bandera){
	//	printf("Nombre: ");
		scanf("%[^\n]",cadena);
		fflush(stdin);		
		if(strlen(cadena)>9){
			continue;
		}else{
			for(int i = 0; i<strlen(cadena); i++){
				if(isalpha(cadena[i])){
					if (i== (strlen(cadena)-1)){									
						strcpy(strupr(cadena), cadena); 
						bandera=false;
					}
				}else{
					break;
				}
			}
		}				
	} 
}

