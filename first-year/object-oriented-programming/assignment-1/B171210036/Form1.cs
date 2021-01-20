using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.IO;

namespace B171210036
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void button1_Click_1(object sender, EventArgs e)
        {
            Stream mystream;
            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            if (openFileDialog1.ShowDialog() == (System.Windows.Forms.DialogResult.OK))
            {
                if ((mystream = openFileDialog1.OpenFile()) != null)
                {
                    string dosyaAdı = openFileDialog1.FileName;
                    string dosyaMetni = File.ReadAllText(dosyaAdı);
                    richTextBox1.Text = dosyaMetni;
                }
            }
        }
        private void button2_Click_1(object sender, EventArgs e)
        {

            dosyayıTara();
            maasHesapla();
            textBoxlaraDegerAta();
        }

        private string tcKimlik = " ";
        private string ad = " ";
        private string soyad = " ";
        private int yaş = 0;
        private int çalışmaSüresi = 0;
        private char evlilikDurumu = '\0';
        private char eşiÇalışıyorMu = '\0';
        private int çocukSayısı = 0;
        private int tabanMaaş;
        private int makamTazminatı = 0;
        private int idariGörevTazminatı = 0;
        private int fazlaMesaiSaati = 0;
        private int fazlaMesaiSaatÜcreti = 0;
        private int vergiMatrahı = 0;
        private string resimYolu = " ";

        private int bürütMaaş = 0;
        private int damgaVergisi = 0;
        private int gelirVergisi = 0;
        private int emekliKesintisi = 0;
        private int netMaaş;

        private void dosyayıTara()
        {
            string arananTC;
            string[] satirlar;
            string[] kelimeler = new string[500];
            string hepsi = richTextBox1.Text;
            satirlar = hepsi.Split('\n');
            arananTC = textBox1.Text;

            foreach (string kelime in satirlar)
            {
                kelimeler = kelime.Split(' ');

                for (int i = 0; i < kelimeler.Length; i++)
                {
                    if (kelimeler[i] == arananTC)
                    {
                        degerleriDegiskenlereAta(kelimeler, i);
                    }
                }
            }
        }

        private void degerleriDegiskenlereAta(string[] kelimeler, int i)
        {
            tcKimlik = kelimeler[i];
            ad = kelimeler[i + 1];
            soyad = kelimeler[i + 2];
            yaş = Convert.ToInt32(kelimeler[i + 3]);
            çalışmaSüresi = Convert.ToInt32(kelimeler[i + 4]);
            evlilikDurumu = Convert.ToChar(kelimeler[i + 5]);
            eşiÇalışıyorMu = Convert.ToChar(kelimeler[i + 6]);
            çocukSayısı = Convert.ToInt32(kelimeler[i + 7]);
            tabanMaaş = Convert.ToInt32(kelimeler[i + 8]);
            makamTazminatı = Convert.ToInt32(kelimeler[i + 9]);
            idariGörevTazminatı = Convert.ToInt32(kelimeler[i + 10]);
            fazlaMesaiSaati = Convert.ToInt32(kelimeler[i + 11]);
            fazlaMesaiSaatÜcreti = Convert.ToInt32(kelimeler[i + 12]);
            vergiMatrahı = Convert.ToInt32(kelimeler[i + 13]);
            resimYolu = kelimeler[i + 14];
        }
        private void maasHesapla()
        {
            {
                if (evlilikDurumu == 'H')
                    bürütMaaş = tabanMaaş + makamTazminatı + idariGörevTazminatı + (çocukSayısı * 30) + (fazlaMesaiSaati * fazlaMesaiSaatÜcreti);

                else if (evlilikDurumu == 'E' && eşiÇalışıyorMu == 'E')
                    bürütMaaş = tabanMaaş + makamTazminatı + idariGörevTazminatı + (çocukSayısı * 30) + (fazlaMesaiSaati * fazlaMesaiSaatÜcreti);

                else if (evlilikDurumu == 'E' && eşiÇalışıyorMu == 'H')
                    bürütMaaş = tabanMaaş + makamTazminatı + idariGörevTazminatı + 200 + (çocukSayısı * 30) + (fazlaMesaiSaati * fazlaMesaiSaatÜcreti);
            }
            damgaVergisi = (bürütMaaş * 10) / 100;

            {
                if (bürütMaaş < 10000)
                    gelirVergisi = (bürütMaaş * 15) / 100;

                else if (bürütMaaş >= 10000 && bürütMaaş < 20000)
                    gelirVergisi = (bürütMaaş * 20) / 100;

                else if (bürütMaaş >= 20000 && bürütMaaş < 30000)
                    gelirVergisi = (bürütMaaş * 25) / 100;

                else
                    gelirVergisi = (bürütMaaş * 30) / 100;
            }

            emekliKesintisi = (bürütMaaş * 15) / 100;

            netMaaş = (bürütMaaş - (emekliKesintisi + gelirVergisi + damgaVergisi));
        }

        private void textBoxlaraDegerAta()
        {
            textBox2.Text = tcKimlik;
            textBox3.Text = ad;
            textBox4.Text = soyad;
            textBox5.Text = Convert.ToString(yaş);
            textBox6.Text = Convert.ToString(çalışmaSüresi);
            textBox7.Text = Convert.ToString(evlilikDurumu);
            textBox8.Text = Convert.ToString(eşiÇalışıyorMu);
            textBox9.Text = Convert.ToString(çocukSayısı);
            textBox10.Text = Convert.ToString(tabanMaaş);
            textBox11.Text = Convert.ToString(makamTazminatı);
            textBox12.Text = Convert.ToString(idariGörevTazminatı);
            textBox13.Text = Convert.ToString(fazlaMesaiSaati);
            textBox14.Text = Convert.ToString(fazlaMesaiSaatÜcreti);
            textBox15.Text = Convert.ToString(vergiMatrahı);
            textBox16.Text = resimYolu;
            textBox17.Text = Convert.ToString(netMaaş) + "₺";
            //pictureBox1.Image = Image.FromFile(resimYolu);
        }
    }
}
