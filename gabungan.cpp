size_t totalMemory = 0;
    totalMemory += sizeof(nama);
    totalMemory += sizeof(warna);
    totalMemory += sizeof(berat);
    totalMemory += sizeof(harga);
    totalMemory += sizeof(rasa);

    cout << "Penggunaan memori Linked List dengan Array: " << totalMemory << " bytes" << endl;
}
