# Tugas-Besar-IF2110/Algoritma-dan-Struktur-Data
## Deskripsi
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
1. Inisiasi<br />
Pada saat program pertama kali dijalankan, pengguna dapat menginisiasi aplikasi atau keluar dari aplikasi. Terdapat splash screen yang menandakan program berjalan dan muncul sebelum program meminta command pertama (START/EXIT) kepada pengguna.<br />
Command-command pada fase ini adalah sebagai berikut:<br />
START<br />
Memulai aplikasi dan menginisiasi aplikasi dengan membaca file eksternal yang berisi konfigurasi aplikasi.<br />
EXIT<br />
Keluar dari aplikasi.<br />
Setelah command START dijalankan, aplikasi akan memiliki seluruh informasi yang dibutuhkan, seperti layout peta dan isinya, informasi makanan yang valid, dan pohon resep yang valid.<br />

2. Simulator<br />
Simulator merupakan representasi BNMO pada aplikasi.<br />
Simulator memiliki beberapa informasi minimal yang harus disimpan, di antaranya:<br />
Nama pengguna simulator<br />
Lokasi simulator di peta saat ini<br />
Inventory makanan yang disimpan<br />
Simulator dapat digerakkan pada peta sesuai yang akan dijelaskan pada bagian Peta.<br />
Simulator dapat melakukan aksi-aksi tertentu sesuai tempat yang adjacent terhadapnya, aksi-aksi ini dijelaskan pada bagian Pengolahan Makanan.<br />

3. Makanan<br />
Makanan merupakan apapun yang bisa dimasak dan dimakan baik bahan mentah maupun matang.<br />
Struktur data Makanan terdiri dari id makanan, nama makanan, waktu kedaluwarsa, lokasi aksi makanan, dan lama pengiriman makanan.<br />
Waktu kedaluwarsa memanfaatkan struktur data Waktu/Time yang terdiri atas hari, jam dan menit.<br />
Lokasi aksi makanan merupakan lokasi tempat eksekusi makanan seperti pemotongan, penggorengan, pembelian, dsb, dapat dilakukan. Contoh : Ayam Mentah memiliki lokasi aksi di tempat telepon setelah dilakukan pembelian (BUY) sedangkan Ayam Goreng memiliki lokasi aksi di tempat menggoreng setelah dilakukan aksi penggorengan (FRY).<br />
Lama pengiriman makanan (delivery time) merupakan waktu yg dibutuhkan oleh simulator untuk mendapatkan makanan pada inventory setelah melakukan pembelian. Penjelasan tambahan dapat dilihat pada bagian Pemesanan Bahan Makanan dan Delivery.<br />
Makanan yang valid didefinisikan terlebih dahulu pada file konfigurasi aplikasi.<br />

4. Resep<br />
Resep merupakan kumpulan makanan yang direpresentasikan dengan  N-ary tree.<br />
Daftar resep yang valid didefinisikan pada konfigurasi file.<br />
Setiap parent makanan dapat beralokasisal dari satu maupun lebih node makanan yang menghasilkan suatu makanan baru. Untuk detail setiap operasi yang dapat dilakukan untuk dapat menghasilkan makanan baru akan dijelaskan pada Pengolahan Makanan.<br />

5. Inventory<br />
Terdapat inventory yang dapat digunakan untuk mengecek makanan yang dipunyai. <br />
Karena semua makanan memiliki atribut waktu kedaluwarsa, maka inventory yang dibuat menggunakan struktur data priority queue, semakin dekat suatu makanan dengan waktu kedaluwarsanya, maka semakin tinggi prioritasnya. <br />
Jika suatu makanan sudah melewati batas expired, maka makanan akan langsung dikeluarkan otomatis dari inventorynya. 
Inventory diimplementasikan dengan struktur data priority queue dengan pendekatan list dinamik. Prinsip priority queue diperlukan untuk proses penyimpanan makanan dengan expiry agar lebih mudah. Sedangkan pendekatan list dinamik diperlukan agar mempermudah proses dequeue.<br />
Inventory akan dianggap sebagai Prio Queue saat melakukan insert (dengan enqueue) dan dequeue (jika Head memiliki expired kurang dari sama dengan 0). Tetapi tidak menutup kemungkinan diperlakukan seperti array list untuk mencari di elemennya dan melakukan remove element dari queue (jangan lupa untuk dimajukan).<br />

6. Pemesanan Bahan Makanan dan Delivery<br />
Untuk melakukan pemesanan bahan makanan, gunakan command BUY.<br />
Pemesanan hanya dapat dilakukan ketika simulator berada secara adjacent dengan “telepon” di peta.<br />
Terdapat sebuah delivery time untuk pemesanan masing-masing bahan, pada saat delivery time sudah mencapai 0, bahan makanan yang dipesan akan masuk pada inventory pemain.<br />
Simulator dapat melihat pemesanan makanan dengan command DELIVERY.<br />
Jumlah bahan makanan yang dapat dibeli diasumsikan tidak terbatas.<br />
Implementasi daftar pesanan menggunakan struktur data priority queue.<br />

7. Peta<br />
Peta bertujuan untuk menunjukkan navigasi BNMO dari satu tempat ke tempat lainnya untuk tujuan-tujuan tertentu.<br />
Peta berukuran N x M dengan ukuran minimal 10 x 10 dengan titik (i, j) merupakan sebuah petak pada baris ke-i dan kolom ke-j.<br />
Ukuran peta akan didefinisikan melalui file yang dibaca.<br />
Command pada peta yang valid: MOVE NORTH / MOVE EAST / MOVE WEST / MOVE SOUTH yang masing-masing dapat menggerakkan BNMO sebanyak satu satuan sesuai dengan arah mata angin.<br />
Simulator (S) tidak dapat menabrak atau melewati titik lokasi suatu tempat pada peta termasuk tempat telepon (T), tempat mixing (M), tempat menggoreng (F), tempat memotong (C), dan tempat merebus (B). Jika BNMO/<br />Simulator (S) ingin memakai fitur dari suatu tempat, cukup cek adjacent dari lokasi BNMO/Simulator (S) pada saat itu.<br />
Peta diberi batasan berupa simbol * dan simulator tidak dapat melewati batasan tersebut. Karakter pada peta melambangkan lokasi-lokasi dari tempat pada peta tersebut. Berikut adalah legenda dari peta:
- Karakter ‘S’ adalah lokasi simulator atau BNMO saat ini berada.
- Karakter ‘T’ adalah lokasi telepon tempat BNMO dapat memesan bahan makanan.
- Karakter ‘M’ adalah lokasi tempat BNMO dapat melakukan mixing bahan makanan.
- Karakter ‘C’ adalah lokasi tempat BNMO dapat melakukan pemotongan bahan makanan.
- Karakter ‘F’ adalah lokasi tempat BNMO dapat menggoreng bahan makanan.
- Karakter ‘B’ adalah lokasi tempat BNMO dapat merebus bahan makanan.
- Karakter ‘X’ adalah tembok yang tidak bisa dilewati oleh BNMO.

8. Pengolahan Makanan<br />
Terdapat beberapa operasi aksi yang dapat dilakukan terhadap makanan atau bahan makanan. Aksi-aksi tersebut adalah sebagai berikut:<br />
- Mix<br />
Mix merupakan command untuk mencampurkan dua atau lebih makanan menjadi satu makanan.<br />
Command ini hanya dapat dilakukan di lokasi mix (M) pada peta.<br />
- Chop<br />
CHOP merupakan command untuk memotong satu bahan makanan menjadi bahan yang sudah terpotong.<br />
Command ini hanya dapat dilakukan di lokasi chop (C) pada peta.<br />
- Fry<br />
FRY merupakan command untuk menggoreng satu atau lebih bahan makanan. Command ini selalu memerlukan minyak goreng pada inventory (atau bahan lain tergantung dari tree resep yang didefinisikan).<br />
Command ini hanya dapat dilakukan di lokasi fry (F) pada peta.<br />
- Boil<br />
BOIL merupakan command untuk merebus bahan makanan.<br />
Command ini hanya dapat dilakukan di lokasi boil (B) pada peta.<br />

9. Mekanisme Waktu<br />
Pada saat aplikasi berjalan, setiap command perpindahan yang dilakukan oleh BNMO dan setiap command yang terkait pengolahan makanan (BUY, MIX, CHOP, FRY, BOIL), waktu pada aplikasi akan bertambah satu menit. Keberjalanan waktu ini kemudian dapat mengurangi waktu kedaluwarsa dari makanan yang disimpan. Selain itu, keberjalanan waktu ini juga mengurangi waktu delivery dari makanan yang dipesan.<br />
Simulator dapat menunggu waktu tertentu dengan command WAIT x y dengan x adalah jam dan y adalah menit untuk diam tidak melakukan apa-apa dan hanya menambah waktu.<br />

10. Undo/Redo<br />
Karena aplikasi ini merupakan simulasi, simulator dapat melakukan kesalahan. Command UNDO bertujuan untuk membatalkan command yang dilakukan oleh simulator dan mengembalikan state aplikasi ke sebelum command itu dieksekusi. Aplikasi juga dapat melakukan command REDO untuk membatalkan command UNDO.<br />
Command undo/redo juga berlaku apabila makanan selesai diantar atau kadaluwarsa.<br />

11. Catalog<br />
Command ini bertujuan untuk menampilkan bahan dan makanan yang tersedia pada aplikasi termasuk informasi detailnya.<br />

12. Cookbook<br />
Command ini bertujuan untuk menampilkan resep-resep yang tersedia pada sistem.<br />

13. Notifikasi<br />
Notifikasi berguna untuk memberikan informasi atas suatu event kepada simulator agar simulator tahu apa yang sedang terjadi pada programnya.<br />
Setiap event yang terjadi pada program ditampilkan pada tampilan program untuk memberitahu pengguna bahwa event tersebut terjadi.<br />
Event-event tersebut di antaranya:<br />
- Makanan sudah masuk ke inventory dari delivery<br />
- Makanan pada inventory sudah kedaluwarsa<br />
- Command undo dan redo dieksekusi<br />

14. Waktu pengolahan makanan<br />
Waktu pengolahan makanan untuk chop, fry, boil, dan mix berbeda satu sama lain<br />

15. Rekomendasi makanan<br />
Command rekomendasi dapat dipanggil untuk memberikan daftar makanan yang dapat dibuat dari bahan yang dimiliki di inventory<br />

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
Athif Nirwasito (13521053):<br />
Inisiasi, Splash Screen, Command Parser, Mesin karakter, Mesin kata, Notifikasi

Moh. Aghna Maysan Abyan (13521076):<br />
Mekanisme Waktu

Christian Albert Hasiholan (13521078):<br />
Queue Prioritas, Stack Umum, Mekansime Waktu, Mekanisme Delivery dan Inventory

Farizki Kurniawan (13521082):
Simulator, Point, Draft Main, Lanjutan Mekanisme Waktu, Mekanisme delivery dan Inventory

Muhamad Aji Wibisono (13521095):<br />
Makanan, List Statik, Tree, Lanjutan Main, Waktu Memasak, Rekomendasi

Vieri Fajar Firdaus (13521099):<br />
Matriks, Map, Mekanisme Movement, Stack Undo Redo

