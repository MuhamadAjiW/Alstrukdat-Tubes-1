# Tugas-Besar-IF2110/Algoritma-dan-Struktur-Data
## deskripsi
Program ini adalah hasil tugas besar untuk mata kuliah IF2110 Algoritma dan struktur data oleh kelompok KlmpkMMMMMmmmmzzzzz yang beranggotakan:

1. Athif Nirwasito/13521053
2. Moh. Aghna Maysan Abyan/13521076
3. Christian Albert Hasiholan/13521078
4. Farizki Kurniawan/13521082
5. Muhamad Aji Wibisono/13521095
6. Vieri Fajar Firdaus/13521099

Dalam tugas ini kami diberi perintah untuk membuat sebuah permainan sederhana yang menggunakan ADT yang telah dipelajari di dalam kelas.

Permainan yang dibuat yakni sebuah permainan memasak dengan fitur - fitur yang tercantum di bagian fitur

## Run
Cara kompilasi program yaitu dengan membuka terminal pada folder utama lalu mengetik (pastikan gcc sudah terinstall)

> gcc main.c -o main

atau pada windows

> gcc main.c -o main.exe

Setelah itu jalankan program dengan

> ./main

atau pada windows bisa dengan klik dua kali main.exe

## Fitur
1. Inisiasi
Pada saat program pertama kali dijalankan, pengguna dapat menginisiasi aplikasi atau keluar dari aplikasi. Terdapat splash screen yang menandakan program berjalan dan muncul sebelum program meminta command pertama (START/EXIT) kepada pengguna.
Command-command pada fase ini adalah sebagai berikut:
- START
Memulai aplikasi dan menginisiasi aplikasi dengan membaca file eksternal yang berisi konfigurasi aplikasi.
- EXIT
Keluar dari aplikasi.
Setelah command START dijalankan, aplikasi akan memiliki seluruh informasi yang dibutuhkan, seperti layout peta dan isinya, informasi makanan yang valid, dan pohon resep yang valid.

2. Simulator
Simulator merupakan representasi BNMO pada aplikasi.
Simulator memiliki beberapa informasi minimal yang harus disimpan, di antaranya:
Nama pengguna simulator
Lokasi simulator di peta saat ini
Inventory makanan yang disimpan
Simulator dapat digerakkan pada peta sesuai yang akan dijelaskan pada bagian Peta.
Simulator dapat melakukan aksi-aksi tertentu sesuai tempat yang adjacent terhadapnya, aksi-aksi ini dijelaskan pada bagian Pengolahan Makanan.

3. Makanan
Makanan merupakan apapun yang bisa dimasak dan dimakan baik bahan mentah maupun matang.
Struktur data Makanan terdiri dari id makanan, nama makanan, waktu kedaluwarsa, lokasi aksi makanan, dan lama pengiriman makanan.
Waktu kedaluwarsa memanfaatkan struktur data Waktu/Time yang terdiri atas hari, jam dan menit.
Lokasi aksi makanan merupakan lokasi tempat eksekusi makanan seperti pemotongan, penggorengan, pembelian, dsb, dapat dilakukan. Contoh : Ayam Mentah memiliki lokasi aksi di tempat telepon setelah dilakukan pembelian (BUY) sedangkan Ayam Goreng memiliki lokasi aksi di tempat menggoreng setelah dilakukan aksi penggorengan (FRY).
Lama pengiriman makanan (delivery time) merupakan waktu yg dibutuhkan oleh simulator untuk mendapatkan makanan pada inventory setelah melakukan pembelian. Penjelasan tambahan dapat dilihat pada bagian Pemesanan Bahan Makanan dan Delivery.
Makanan yang valid didefinisikan terlebih dahulu pada file konfigurasi aplikasi.

4. Resep
Resep merupakan kumpulan makanan yang direpresentasikan dengan  N-ary tree.
Daftar resep yang valid didefinisikan pada konfigurasi file.
Setiap parent makanan dapat beralokasisal dari satu maupun lebih node makanan yang menghasilkan suatu makanan baru. Untuk detail setiap operasi yang dapat dilakukan untuk dapat menghasilkan makanan baru akan dijelaskan pada Pengolahan Makanan.

5. Inventory
Terdapat inventory yang dapat digunakan untuk mengecek makanan yang dipunyai. 
Karena semua makanan memiliki atribut waktu kedaluwarsa, maka inventory yang dibuat menggunakan struktur data priority queue, semakin dekat suatu makanan dengan waktu kedaluwarsanya, maka semakin tinggi prioritasnya. 
Jika suatu makanan sudah melewati batas expired, maka makanan akan langsung dikeluarkan otomatis dari inventorynya. 
Inventory diimplementasikan dengan struktur data priority queue dengan pendekatan list dinamik. Prinsip priority queue diperlukan untuk proses penyimpanan makanan dengan expiry agar lebih mudah. Sedangkan pendekatan list dinamik diperlukan agar mempermudah proses dequeue.
Inventory akan dianggap sebagai Prio Queue saat melakukan insert (dengan enqueue) dan dequeue (jika Head memiliki expired kurang dari sama dengan 0). Tetapi tidak menutup kemungkinan diperlakukan seperti array list untuk mencari di elemennya dan melakukan remove element dari queue (jangan lupa untuk dimajukan).

6. Pemesanan Bahan Makanan dan Delivery
Untuk melakukan pemesanan bahan makanan, gunakan command BUY.
Pemesanan hanya dapat dilakukan ketika simulator berada secara adjacent dengan “telepon” di peta.
Terdapat sebuah delivery time untuk pemesanan masing-masing bahan, pada saat delivery time sudah mencapai 0, bahan makanan yang dipesan akan masuk pada inventory pemain.
Simulator dapat melihat pemesanan makanan dengan command DELIVERY.
Jumlah bahan makanan yang dapat dibeli diasumsikan tidak terbatas.
Implementasi daftar pesanan menggunakan struktur data priority queue.

7. Peta
Peta bertujuan untuk menunjukkan navigasi BNMO dari satu tempat ke tempat lainnya untuk tujuan-tujuan tertentu.
Peta berukuran N x M dengan ukuran minimal 10 x 10 dengan titik (i, j) merupakan sebuah petak pada baris ke-i dan kolom ke-j.
Ukuran peta akan didefinisikan melalui file yang dibaca.
Command pada peta yang valid: MOVE NORTH / MOVE EAST / MOVE WEST / MOVE SOUTH yang masing-masing dapat menggerakkan BNMO sebanyak satu satuan sesuai dengan arah mata angin.
Simulator (S) tidak dapat menabrak atau melewati titik lokasi suatu tempat pada peta termasuk tempat telepon (T), tempat mixing (M), tempat menggoreng (F), tempat memotong (C), dan tempat merebus (B). Jika BNMO/Simulator (S) ingin memakai fitur dari suatu tempat, cukup cek adjacent dari lokasi BNMO/Simulator (S) pada saat itu.

Peta diberi batasan berupa simbol * dan simulator tidak dapat melewati batasan tersebut. Karakter pada peta melambangkan lokasi-lokasi dari tempat pada peta tersebut. Berikut adalah legenda dari peta:
- Karakter ‘S’ adalah lokasi simulator atau BNMO saat ini berada.
- Karakter ‘T’ adalah lokasi telepon tempat BNMO dapat memesan bahan makanan.
- Karakter ‘M’ adalah lokasi tempat BNMO dapat melakukan mixing bahan makanan.
- Karakter ‘C’ adalah lokasi tempat BNMO dapat melakukan pemotongan bahan makanan.
- Karakter ‘F’ adalah lokasi tempat BNMO dapat menggoreng bahan makanan.
- Karakter ‘B’ adalah lokasi tempat BNMO dapat merebus bahan makanan.
- Karakter ‘X’ adalah tembok yang tidak bisa dilewati oleh BNMO.

8. Pengolahan Makanan
Terdapat beberapa operasi aksi yang dapat dilakukan terhadap makanan atau bahan makanan. Aksi-aksi tersebut adalah sebagai berikut:
- Mix
Mix merupakan command untuk mencampurkan dua atau lebih makanan menjadi satu makanan.
Command ini hanya dapat dilakukan di lokasi mix (M) pada peta.
- Chop
CHOP merupakan command untuk memotong satu bahan makanan menjadi bahan yang sudah terpotong.
Command ini hanya dapat dilakukan di lokasi chop (C) pada peta.
- Fry
FRY merupakan command untuk menggoreng satu atau lebih bahan makanan. Command ini selalu memerlukan minyak goreng pada inventory (atau bahan lain tergantung dari tree resep yang didefinisikan).
Command ini hanya dapat dilakukan di lokasi fry (F) pada peta.
- Boil
BOIL merupakan command untuk merebus bahan makanan.
Command ini hanya dapat dilakukan di lokasi boil (B) pada peta.

9. Mekanisme Waktu
- Pada saat aplikasi berjalan, setiap command perpindahan yang dilakukan oleh BNMO dan setiap command yang terkait pengolahan makanan (BUY, MIX, CHOP, FRY, BOIL), waktu pada aplikasi akan bertambah satu menit. Keberjalanan waktu ini kemudian dapat mengurangi waktu kedaluwarsa dari makanan yang disimpan. Selain itu, keberjalanan waktu ini juga mengurangi waktu delivery dari makanan yang dipesan.
- Simulator dapat menunggu waktu tertentu dengan command WAIT x y dengan x adalah jam dan y adalah menit untuk diam tidak melakukan apa-apa dan hanya menambah waktu.

10. Undo/Redo
Karena aplikasi ini merupakan simulasi, simulator dapat melakukan kesalahan. Command UNDO bertujuan untuk membatalkan command yang dilakukan oleh simulator dan mengembalikan state aplikasi ke sebelum command itu dieksekusi. Aplikasi juga dapat melakukan command REDO untuk membatalkan command UNDO.

Command undo/redo juga berlaku apabila makanan selesai diantar atau kadaluwarsa.

11. Catalog
Command ini bertujuan untuk menampilkan bahan dan makanan yang tersedia pada aplikasi termasuk informasi detailnya.

12. Cookbook
Command ini bertujuan untuk menampilkan resep-resep yang tersedia pada sistem.

13. Notifikasi
Notifikasi berguna untuk memberikan informasi atas suatu event kepada simulator agar simulator tahu apa yang sedang terjadi pada programnya.
Setiap event yang terjadi pada program ditampilkan pada tampilan program untuk memberitahu pengguna bahwa event tersebut terjadi.
Event-event tersebut di antaranya:
Makanan sudah masuk ke inventory dari delivery
Makanan pada inventory sudah kedaluwarsa
Command undo dan redo dieksekusi

Contoh untuk event pada command undo:
Simulator membatalkan eksekusi FRY dengan command undo, maka tampilkan notifikasi “Penggorengan makanan X dibatalkan”. 
Makanan selesai diantar / kedaluwarsa pada suatu waktu dan simulator mengeksekusi command undo, maka tampilkan notifikasi “Makanan X dihapus dari inventory” atau “Makanan X dikembalikan ke inventory”.
Makanan sudah kedaluwarsa dan dihapus dari inventory, tampilkan notifikasi “Makanan X sudah kedaluwarsa”.

Hal yang sama juga terjadi pada saat command redo dieksekusi.

14. Waktu pengolahan makanan
Waktu pengolahan makanan untuk chop, fry, boil, dan mix berbeda satu sama lain

15. Rekomendasi makanan
Command rekomendasi dapat dipanggil untuk memberikan daftar makanan yang dapat dibuat dari bahan yang dimiliki di inventory

Status pengerjaan
1. Inisiasi (selesai)
2. Simulator (selesai)
3. Makanan (selesai)
4. Resep (selesai)
5. Inventory (selesai)
6. Pemesanan Bahan Makanan dan Delivery (selesai)
7. Peta (selesai)
8. Pengolahan Makanan (selesai)
9. Mekanisme Waktu (selesai)
10. Undo/Redo (selesai)
11. Catalog (selesai)
12. Cookbook (selesai)
13. Notifikasi (selesai)
14. Waktu pengolahan makanan (selesai)
15. Rekomendasi makanan (selesai)

Pada spesifikasi yang diberikan terdapat beberapa fitur tambahan yang tidak kami kerjakan, yaitu
1. Kulkas
2. Auto-BNMO

## Pembagian Tugas
Athif Nirwasito (13521053):
Inisiasi, Splash Screen, Command Parser, Mesin karakter, Mesin kata, Notifikasi

Moh. Aghna Maysan Abyan (13521076):
Mekanisme Waktu

Christian Albert Hasiholan (13521078):
Queue Prioritas, Stack Umum, Mekansime Waktu, Mekanisme Delivery dan Inventory

Farizki Kurniawan (13521082):
Simulator, Point, Draft Main, Lanjutan Mekanisme Waktu, Mekanisme delivery dan Inventory

Muhamad Aji Wibisono (13521095):
Makanan, List Statik, Tree, Lanjutan Main, Waktu Memasak, Rekomendasi

Vieri Fajar Firdaus (13521099):
Matriks, Map, Mekanisme Movement, Stack Undo Redo

