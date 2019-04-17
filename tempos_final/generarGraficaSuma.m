clear all
clf

%CARGA DE DATOS
t=load('out_suma.txt'); %Carga en memoria el fichero


x=t(:,1); %Eje x: n, primera columna
y_bs=t(:,2); %Eje y: tiempos t(n), segunda columna

pol=polyfit(x,y_bs,2); % ajustamos los puntos por minimos cuadrados a un polinomio de grado 2

yajustadas = polyval(pol,x);

%REPRESENTACI�N GR�FICA

plot(x, y_bs, '*b', x, yajustadas, '-r' ); 

legend('empirica','ajuste');


title('Suma de matrices');
xlabel ('Tama�o de la matriz NxN');
ylabel ('Tiempo (segs)');

