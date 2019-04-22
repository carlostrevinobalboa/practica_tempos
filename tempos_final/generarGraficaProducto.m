clear all
clf

%CARGA DE DATOS
t=load('tiempoprod.txt'); %Carga en memoria el fichero


x=t(:,1); %Eje x: n, primera columna
y_bs=t(:,2); %Eje y: tiempos t(n), segunda columna

pol=polyfit(x,y_bs,5); % ajustamos los puntos por minimos cuadrados a un polinomio de grado 3

yajustadas = polyval(pol,x);

%REPRESENTACIÓN GRÁFICA

plot(x, y_bs, '*b', x, yajustadas, '-r' ); 

legend('empirica','ajuste');


title('Multiplicación de matrices');
xlabel ('Tamaño de la matriz NxN');
ylabel ('Tiempo (segs)');

