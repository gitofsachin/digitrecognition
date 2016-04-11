function [trainimage,traindata,testimage,testdata] = readdata(imagesreqd)

curfile = './MNIST/train-images.idx3-ubyte';
fptr = fopen(curfile,'r','b');
junknum = fread(fptr,1,'int32');
if(junknum~=2051) 
    display('Error in syntax');
    return;
end
noofimage = fread(fptr,1,'int32');
rowsize = fread(fptr,1,'int32');
columnsize = fread(fptr,1,'int32');

if(imagesreqd<noofimage) 
    noofimage=imagesreqd; 
end

for k=1:noofimage
        trainimage{k} = uint8(fread(fptr,[rowsize columnsize],'uchar'));
		trainimage{k}=trainimage{k}';
end
fclose(fptr);


curfile = './MNIST/train-labels.idx1-ubyte';
fptr = fopen(curfile,'r','b');
junknum = fread(fptr,1,'int32');
if(junknum~=2049) 
    display('Error in syntax');
    return;
end
datanum = fread(fptr,1,'int32');

if(imagesreqd<datanum) 
    datanum=imagesreqd; 
end

traindata = uint8(fread(fptr,datanum,'uint8'));

fclose(fptr);

curfile = './MNIST/t10k-images.idx3-ubyte';
fptr = fopen(curfile,'r','b');
junknum = fread(fptr,1,'int32');
if(junknum~=2051) 
    display('Error in syntax');
    return;
end
noofimage = fread(fptr,1,'int32');
rowsize = fread(fptr,1,'int32');
columnsize = fread(fptr,1,'int32');

if(imagesreqd<noofimage) 
    noofimage=imagesreqd; 
end

for k=1:noofimage
        testimage{k} = uint8(fread(fptr,[rowsize columnsize],'uchar'));
end
fclose(fptr);


curfile = './MNIST/t10k-labels.idx1-ubyte';
fptr = fopen(curfile,'r','b');
junknum = fread(fptr,1,'int32');
if(junknum~=2049) 
    display('Error in syntax');
    return;
end
datanum = fread(fptr,1,'int32');
if(imagesreqd<datanum) 
    datanum=imagesreqd; 
end
testdata = uint8(fread(fptr,datanum,'uint8'));

fclose(fptr);
