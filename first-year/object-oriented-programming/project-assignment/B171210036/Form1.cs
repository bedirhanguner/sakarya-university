/*****************************************************************************************************************************************************************
**                                                    					SAKARYA ÜNİVERSİTESİ
**                                                    			BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**                                                    				  BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**                                                    			     NESNEYE DAYALI PROGRAMLAMA DERSİ
**                                                    				    2018-2019 BAHAR DÖNEMİ
**                                                    	                      PROJE ÖDEVİ 
**                                                    				        
**                                                    				    ÖĞRENCİ ADI: Bedirhan Güner
**				                                                        ÖĞRENCİ NUMARASI: B171210036
**                                                                      DERSİN ALINDIĞI GRUP: D
*****************************************************************************************************************************************************************/

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Media;

namespace B171210036_1D_PROJE
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            timer1.Enabled = true;
            timer1.Interval = 1000;
            
        }

        int saniye = 0;
        int kasadakiPara = 0;

        Tavuk tavuk = new Tavuk(100, 0, 1,2,3);
        Ordek ordek = new Ordek(100, 0, 3,3,5);
        Inek inek = new Inek(100, 0, 5,8,8);
        Keci keci = new Keci(100, 0, 8,6,7);

        private void timer1_Tick(object sender, EventArgs e)
        {
            saniye++;
            gecenSure.Text = saniye + " SN";

            {
                if (tavukCanBar.Value > 0 && tavukCanBar.Value <= 100)
                {
                    tavukCanBar.Value = tavuk.CanAzalt();

                    if (tavukCanBar.Value <= tavuk.CanAzalmaMiktari)
                    {
                        tavukCanBar.Value = 0;
                        label17.Text = "ÖLÜ";

                        SoundPlayer tavukSesi = new SoundPlayer();
                        string tavukSesYolu = Application.StartupPath.ToString() + "\\tavuk.wav";
                        tavukSesi.SoundLocation = tavukSesYolu;
                        tavukSesi.Play();

                        string tavukResimYolu = Application.StartupPath.ToString() + "\\tavukOlu.png";
                        this.tavukResim.Image = Image.FromFile(tavukResimYolu);
                    }
                }

                if (ordekCanBar.Value > 0 && ordekCanBar.Value <= 100)
                {
                    ordekCanBar.Value = ordek.CanAzalt();
                    if (ordekCanBar.Value <= ordek.CanAzalmaMiktari)
                    {
                        ordekCanBar.Value = 0;
                        label18.Text = "ÖLÜ";

                        SoundPlayer ordekSesi = new SoundPlayer();
                        string ordekSesYolu = Application.StartupPath.ToString() + "\\ordek.wav";
                        ordekSesi.SoundLocation = ordekSesYolu;
                        ordekSesi.Play();

                        string ordekResimYolu = Application.StartupPath.ToString() + "\\ordekOlu.png";
                        this.ordekResim.Image = Image.FromFile(ordekResimYolu);
                    }
                }
                if (inekCanBar.Value > 0 && inekCanBar.Value <= 100)
                {
                    inekCanBar.Value = inek.CanAzalt();
                    if (inekCanBar.Value <= inek.CanAzalmaMiktari)
                    {
                        inekCanBar.Value = 0;
                        label19.Text = "ÖLÜ";

                        SoundPlayer inekSesi = new SoundPlayer();
                        string inekSesYolu = Application.StartupPath.ToString() + "\\inek.wav";
                        inekSesi.SoundLocation = inekSesYolu;
                        inekSesi.Play();

                        string inekResimYolu = Application.StartupPath.ToString() + "\\inekOlu.png";
                        this.inekResim.Image = Image.FromFile(inekResimYolu);
                    }
                }

                if (keciCanBar.Value > 0 && keciCanBar.Value <= 100)
                {
                    keciCanBar.Value = keci.CanAzalt();
                    if (keciCanBar.Value <= keci.CanAzalmaMiktari)
                    {
                        keciCanBar.Value = 0;
                        label20.Text = "ÖLÜ";

                        SoundPlayer keciSesi = new SoundPlayer();
                        string keciSesYolu = Application.StartupPath.ToString() + "\\keci.wav";
                        keciSesi.SoundLocation = keciSesYolu;
                        keciSesi.Play();

                        string keciResimYolu = Application.StartupPath.ToString() + "\\keciOlu.png";
                        this.keciResim.Image = Image.FromFile(keciResimYolu);
                    }
                }
            }

            {
                if (tavukCanBar.Value > 0)
                {
                    if (saniye % tavuk.UretimSikligi == 0)
                    {
                        tavukYumurtaAdedi.Text = tavuk.YumurtaUret() + " ADET";
                    }
                }

                if (ordekCanBar.Value > 0)
                {
                    if (saniye % ordek.UretimSikligi == 0)
                    {
                        ordekYumurtaAdedi.Text = ordek.YumurtaUret() + " ADET";
                    }
                }

                if (inekCanBar.Value > 0)
                {
                    if (saniye % inek.UretimSikligi == 0)
                    {
                        inekSutMiktari.Text = inek.SutUret() + " KG";
                    }
                }

                if (keciCanBar.Value > 0)
                {
                    if (saniye % keci.UretimSikligi == 0)
                    {
                        keciSutMiktari.Text = keci.SutUret() + " KG";
                    }
                }
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            kasadakiPara += tavuk.YumurtaSat();
            kasa.Text = kasadakiPara + " TL";
            tavukYumurtaAdedi.Text = 0 + " ADET";

        }

        private void button2_Click(object sender, EventArgs e)
        {
            kasadakiPara += ordek.YumurtaSat();
            kasa.Text = kasadakiPara + " TL";
            ordekYumurtaAdedi.Text = 0 + " ADET";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            kasadakiPara += inek.SutSat();
            kasa.Text = kasadakiPara + " TL";
            inekSutMiktari.Text = 0 + " KG";
        }

        private void button4_Click(object sender, EventArgs e)
        {
            kasadakiPara += keci.SutSat();
            kasa.Text = kasadakiPara + " TL";
            keciSutMiktari.Text = 0 + " KG";
        }
        private void button5_Click(object sender, EventArgs e)
        {
            if (tavukCanBar.Value > 0)
            {
                tavuk.CanTazele();
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            if (ordekCanBar.Value > 0)
            {
                ordek.CanTazele();
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            if (inekCanBar.Value > 0)
            {
                inek.CanTazele();
            }
        }
        private void button8_Click(object sender, EventArgs e)
        {
            if (keciCanBar.Value > 0)
            {
                keci.CanTazele();
            }
        }
    }
}