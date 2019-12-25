/* 
 * @Atte Jantunen
 * Kernel written in C
 */


char *fb = (char*)0xb8000; //(Framebuffer) video memory begins here
unsigned int fb_current;
void fb_clear()
{
	unsigned int j = 0;
	/* loop to clear screen
	* 25 lines, each 80 columns, each element takes 2 bytes
	*/
	while(j<80 * 25 *2){
	
		/*blank char*/  
		fb[j] =' ';
		/* attribute-byte - light grey on black*/
		fb[j+1] = 0x07;
			j = j+2;
		}
	j=0;

}

void fb_write(unsigned int i, unsigned char c)
{
		/*chars ascii*/
		fb[i] = c;
		/*attribute-byte -> char black background and light foreground*/
		fb[i+1] = 0x07;
		fb_current = i+2;
}

void kernelmain(void)
{
	unsigned int i=0;
	fb_current=0;
	char *str="JANUX KERNEL";
	fb_clear();
	while(str[i]!='\0') {
		fb_write(fb_current, str[i]);
		++i;
	}

	return;
}
