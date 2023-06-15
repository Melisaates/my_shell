# Shell Programı

Bu shell programı, kullanıcının komutları çalıştırabilmesi için bir kabuk ortamı sağlar. Kullanıcı, programı çalıştırdığında komutları girer ve program bu komutları işler.

## Kullanım

Programı kullanmak için aşağıdaki adımları izleyin:

1. `main` fonksiyonunu içeren C dosyasını indirin veya kopyalayın.
2. C derleyicinizle (gcc gibi) dosyayı derleyin. Örneğin, Linux üzerinde GCC kullanarak aşağıdaki komutu kullanabilirsiniz:

gcc shell.c -o shell

3. Derlenmiş programı çalıştırın:

./shell

4. Program başladığında, bir kabuk etkileşimini temsil eden `>>` işaretçisi belirecektir. Burada komutlarınızı girebilirsiniz.
5. Çalıştırmak istediğiniz komutu girin. Örneğin, `ls`, `cd`, `pwd` gibi standart kabuk komutlarını kullanabilirsiniz.
6. Çalıştırmak istediğiniz komutu girdikten sonra, çıktıları ve herhangi bir hata mesajını göreceksiniz.
7. Çalıştırmak istediğiniz tüm komutları girdikten sonra, `quit` komutunu girerek programı sonlandırabilirsiniz.

Örnek kullanım:
ls
file.txt program.c shell.c
pwd
/home/kullanici/proje
quit
bye bye


## Lisans

Bu proje MIT Lisansı altında lisanslanmıştır. Daha fazla bilgi için [LİSANS](LICENSE) dosyasını inceleyebilirsiniz.


