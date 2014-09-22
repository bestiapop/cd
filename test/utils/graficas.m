function R = graficas()
	R=[];
	path="../test6/data"
	files= ls(path);
	Orden=cellstr(files);
	Orden=sort(Orden);

	for i= 1:rows(files)
	path_file= strcat(path,"/",char(Orden(i)))
	Read=dlmread(path_file,",");
	X=cumsum(Read(:,1));
	Y=Read(:,2);
	xf= X(length(X),1)
	yf= Y(length(Y),1)
	res= yf/xf
	R=[R,res]

	figure(1);
	plot(X,Y);
	title (char(Orden(i)));
	xlabel ("File Length");
	ylabel ("File Compress");
	st= strcat("./graficas",char(Orden(i)),".png");

	print(st,"-dpng");
	endfor
	
	dlmwrite ("./resultadosgraficas.csv", R, "delimiter", ",", "newline", "\\n")
