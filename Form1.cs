using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string[]lines = System.IO.File.ReadAllLines(@"C:\Users\J stock\source\repos\vaccnie project\vaccnie project\stat.txt");

            chart1.Series["vac"].Points.AddXY("not vaccined", lines[0]);
            chart1.Series["vac"].Points.AddXY("dose1 vaccined", lines[1]);
            chart1.Series["vac"].Points.AddXY("fully vaccined", lines[2]);

            chart2.Series["number"].Points.AddXY("men", lines[3]);
            chart2.Series["number"].Points.AddXY("women", lines[4]);
            chart2.Series["number"].Points.AddXY("egyptions", lines[5]);
            chart2.Series["number"].Points.AddXY("forigners", lines[6]);
           
            chart3.Series["governerate"].Points.AddXY("cairo", lines[7]);
            chart3.Series["governerate"].Points.AddXY("alex", lines[8]);
            chart3.Series["governerate"].Points.AddXY("mansora", lines[9]);
            chart3.Series["governerate"].Points.AddXY("sinai", lines[10]);
           
        }

        private void chart2_Click(object sender, EventArgs e)
        {

        }

        private void chart4_Click(object sender, EventArgs e)
        {

        }
    }
}
