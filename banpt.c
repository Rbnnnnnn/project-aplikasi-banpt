#include <stdio.h>

int main() {
    /*Mencari Skor Butir Dosen Tetap*/
    int ndtps, ndgb, ndlk, pgblk;
    float hNDTPS, hPGBLK;

    printf("====PROGRAM PENILAIAN AKREDITASI====\n");
    printf("\t==BAN-PT 2020==\n\n");
    printf("1. Dosen Tetap");
    printf("\nMasukkan Jumlah Dosen Tetap: ");
    scanf("%d", &ndtps);

    if (ndtps >= 6) {
        hNDTPS = 4;
    }
    else if (ndtps < 6 && ndtps >= 3) {
        hNDTPS = (2 * ndtps) / 3;
    }
    else {
        hNDTPS = 0;
    }

    printf("\nSkor DTPS: %.2f", hNDTPS);
    
    printf("\n\nMasukkan Jumlah Dosen dengan Jabatan Guru Besar: ");
    scanf("%d", &ndgb);
    printf("Masukkan Jumlah Dosen dengan Jabatan Lektor Kepala: ");
    scanf("%d", &ndlk);

    pgblk = ((ndgb + ndlk) / ndtps) * 100;

    if (pgblk >= 70) {
        hPGBLK = 4;
    }
    else {
        hPGBLK = 2 + ((20 * pgblk) / 7);
        if (pgblk < 20) {
            hPGBLK = 2;
        }
    }

    printf("\nSkor PGBLK: %.2f", hPGBLK);

    /*Mencari Skor Butir Kurikulum*/
    char kurA, kurB, kurC;
    float hKurikulum;

    printf("\n\n2. Kurikulum");
    printf("\nMasukkan Keterlibatan Pemangku Kepentingan dalam Evalusasi dan Pemutakhiran Kurikulum (0-4): ");
    scanf(" %c", &kurA);
    printf("Masukkan Kesesuaian Capaian Pembelajaran dengan Profil Lulusan & Jenjang KKNI/SSNI (0-4): ");
    scanf(" %c", &kurB);
    printf("Masukkan Ketepatan Struktur Kurikulum dalam Pembentukan Capaian Pembelajaran (1-4): ");
    scanf(" %c", &kurC);

    hKurikulum = (kurA - '0' + (2 * kurB - '0') + (2 * kurC - '0')) / 5;

    printf("\nSkor Kurikulum: %.2f", hKurikulum);

    /*Mencari Skor Butir Kesesuaian Bidang Kerja*/
    int pbs;
    float hKelulusan;

    printf("\n\n3. Kesesuaian Bidang Kerja");
    printf("\nMasukkan Persentase Kesesuaian Pekerjaan Pertama dari Bidang Lulusan (%%): ");
    scanf("%d", &pbs);

    if (pbs >= 60) {
        hKelulusan = 4;
    }else {
        hKelulusan = (20 * pbs) / 3;
    }

    printf("\nSkor Kesesuaian Bidang Kerja: %.2f", hKelulusan);

    /*Fungsi Mencari Kepuasan Pengguna*/
    float hKepuasan, TK;
    int a,b,c,d;

    printf("\n\n4. Kepuasan Pengguna");
    printf("\nTingkat Kepuasaan Pengguna Lulusan Program Studi");
    printf("\nJumlah Responden Yang Menjawab 'Sangat Baik': ");
    scanf(" %d", &a);
    printf("Jumlah Responden Yang Menjawab 'Baik': ");
    scanf(" %d", &b);
    printf("Jumlah Responden Yang Menjawab 'Cukup': ");
    scanf(" %d", &c);
    printf("Jumlah Responden Yang Menjawab 'Kurang': ");
    scanf(" %d", &d);

    TK = ((float)(4 * a) + (3 * b) + (2 * c) + d);
    hKepuasan = TK / 7;

    printf("\nSkor Kepuasan Pengguna: %.2f", hKepuasan);

    /*Function untuk Mencari Data Publikasi Ilmiah Mahasiswa*/
    int pMgA = 2, pMgB = 20, pMgC = 70;
    int mNA1,mNA2,mNA3,mNA4,mNB1,mNB2,mNB3,mNC1,mNC2,mNC3,mNM;
    float MagRI, MagRL, MagRN, hPublikasiMag;

    printf("\n\n5. Publikasi Ilmiah Mahasiswa");
    printf("\na). Prog. Magister\nJumlah Mahasiswa Saat Ini: ");
    scanf("%d", &mNM);
    printf("Jumlah Publikasi Mahasiswa di Jurnal Nasional Tidak Terakreditasi: ");
    scanf("%d", &mNA1);
    printf("Jumlah Publikasi Mahasiswa di Jurnal Nasional Terakreditasi: ");
    scanf("%d", &mNA2);
    printf("Jumlah Publikasi Mahasiswa di Jurnal Internasional: ");
    scanf("%d", &mNA3);
    printf("Jumlah Publikasi Mahasiswa di Jurnal Internasional Bereputasi: ");
    scanf("%d", &mNA4);
    printf("Jumlah Publikasi Mahasiswa di Seminar Wilayah/Lokal/PT: ");
    scanf("%d", &mNB1);
    printf("Jumlah Publikasi Mahasiswa di Seminar Nasional: ");
    scanf("%d", &mNB2);
    printf("Jumlah Publikasi Mahasiswa di Seminar Internasional: ");
    scanf("%d", &mNB3);
    printf("Jumlah Tulisan Mahasiswa di Media Massa Wilayah: ");
    scanf("%d", &mNC1);
    printf("Jumlah Tulisan Mahasiswa di Media Massa Nasional: ");
    scanf("%d", &mNC2);
    printf("Jumlah Tulisan Mahasiswa di Media Massa Internasional: ");
    scanf("%d", &mNC3);

    MagRL = ((mNA1+mNB1+mNC1)/mNM) * 100;
    MagRN = ((mNA2+mNA3+mNB2+mNC2)/mNM) *100;
    MagRI = ((mNA4+mNB3+mNC3)/mNM) * 100;

    if (MagRI >= pMgA) {
        hPublikasiMag = 4;
    }else if (MagRI < pMgA && MagRN >= pMgB) {
        hPublikasiMag = 3 + (MagRI*pMgA);
        if (MagRI > 0 && MagRI < pMgA && MagRN > 0 && MagRN < pMgB) {
            hPublikasiMag = 2 + (2*(MagRI/pMgA)) + (MagRN/pMgB) - ((MagRI*MagRN)/(pMgA*pMgB));
        }
    }else if (MagRI == 0 && MagRN == 0 && MagRL >= pMgC) {
        hPublikasiMag = 2;
        if (MagRI == 0 && MagRN == 0 && MagRL < pMgC) {
            hPublikasiMag = (2 - MagRL) / pMgC;
        }
    }

    printf("\nSkor Publikasi Ilmiah Mahasiswa Prog. Magister: %.2f", hPublikasiMag);

    printf("\n\n======SKOR AKHIR PENILAIAN======");
    printf("\nSkor NDTPS: %.2f", hNDTPS);
    printf("\nSkor PGBLK: %.2f", hPGBLK);
    printf("\nSkor Kurikulum: %.2f", hKurikulum);
    printf("\nSkor Kesesuaian Bidang Kerja: %.2f", hKelulusan);
    printf("\nSkor Kepuasan Pengguna: %.2f", hKepuasan);
    printf("\nSkor Publikasi Ilmiah Mahasiswa: %.2f", hPublikasiMag);
    printf("\n========TERIMAKASIH SUDAH MENGGUNAKAN PROGRAM========");
    printf("\n\t====SAMPAI JUMPA====");

    return 0;
}