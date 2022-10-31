//angka di parameter editMakananTest itu waktu, ganti aja kalo mau
    //buat dan nambah makanan ke queue
    createmakanan(&m1);
    editMakananTest(&m1, 15);
    Enqueue(&q1, m1);

    createmakanan(&m2);
    editMakananTest(&m2, 20);
    Enqueue(&q1, m2);

    createmakanan(&m3);
    editMakananTest(&m3, 17);
    Enqueue(&q1, m3);

    //print isi queue sementara
    PrintPrioQueue(q1);
    printf("\n");

    createmakanan(&m4);
    editMakananTest(&m4, 16);
    Enqueue(&q1, m4);

    PrintPrioQueue(q1);
    printf("\n");
    
    //pop head dari queue
    Dequeue(&q1, &dump);
    Dequeue(&q1, &dump);

    PrintPrioQueue(q1);
    printf("\n");

    editMakananTest(&m1, 22);
    Enqueue(&q1, m1);

    PrintPrioQueue(q1);
    printf("\n");

    editMakananTest(&m1, 19);
    Enqueue(&q1, m1);

    PrintPrioQueue(q1);
    printf("\n");
