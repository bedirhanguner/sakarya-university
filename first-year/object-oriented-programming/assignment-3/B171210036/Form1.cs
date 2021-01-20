using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace B171210036_1D_ODEV3
{
    public partial class Islemler : Form
    {
        public Islemler()
        {
            InitializeComponent();
        }     
        string degerler;
        int elemanSayisi = 0;
        int[] sayiDizisi = new int[100];
        int ilkSayi=0;
        int ikinciSayi=0;
        int cevap = 0;
        string ilkKelime = "";
        string ikinciKelime = "";

        private void Sifirla(ref string ilkKelime, ref string ikinciKelime)
        {
            ilkKelime = "";
            ikinciKelime = "";
        }
        private int ilkSayiBul(string eleman, char aranan)
        {
            for (int i = 0; i < eleman.Length; i++)
            {
                if (eleman[i] == aranan)
                {
                    for (int j = 0; j < i; j++)
                    {
                        ilkKelime += eleman[j];
                    }
                    ilkSayi = Convert.ToInt32(ilkKelime);
                }
            }
            return ilkSayi;
        }

        private int ikinciSayiBul(string eleman, char aranan)
        {
            for (int i = 0; i < eleman.Length; i++)
            {
                if (eleman[i] == aranan)
                {
                    for (int j = i + 1; j < eleman.Length; j++)
                    {
                        ikinciKelime += eleman[j];
                    }
                    ikinciSayi = Convert.ToInt32(ikinciKelime);
                }
            }
            return ikinciSayi;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            degerler = textBox1.Text;
            string[] dizi = degerler.Split('+');

            foreach (string eleman in dizi)
            {
                 if (eleman.Contains('/'))
                {
                    Sifirla(ref ilkKelime, ref ikinciKelime);
                    sayiDizisi[elemanSayisi] = ilkSayiBul(eleman, '/') / ikinciSayiBul(eleman, '/');
                    elemanSayisi++;
                }
                else if (eleman.Contains('*'))
                {
                    Sifirla(ref ilkKelime, ref ikinciKelime);
                    sayiDizisi[elemanSayisi] = ilkSayiBul(eleman, '*') * ikinciSayiBul(eleman, '*');
                    elemanSayisi++;
                }
                else if (eleman.Contains('-'))
                {
                    Sifirla(ref ilkKelime, ref ikinciKelime);
                    sayiDizisi[elemanSayisi] = ilkSayiBul(eleman, '-') - ikinciSayiBul(eleman, '-');
                    elemanSayisi++;
                }
                else
                {
                    sayiDizisi[elemanSayisi] = Convert.ToInt32(eleman);
                    elemanSayisi++;
                }

            }
            foreach (int sayi in sayiDizisi)
            {
                cevap += sayi;
            }
            textBox2.Text=Convert.ToString(cevap);
        }
    }
}
