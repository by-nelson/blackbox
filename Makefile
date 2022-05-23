# Compilation options
BUILDDIR := obj
TARGETDIR := /var/www/blackbox/bin
HOMEDIR := /var/www/blackbox

# Images and Style sheets
CSSDEST := /var/www/blackbox/css
IMGDEST := /var/www/blackbox/images
HTMLDEST := /var/www/blackbox/html

CSSSRC := www/css
IMGSRC := www/images
HTMLSRC := html

VPATH := src:src/core:src/http:src/mem:src/html:src/utils:src/db:src/domain
OBJS := $(addprefix $(BUILDDIR)/, box_headers.o box_array.o box_ntree.o \
		box_html.o box_reader.o box_tags.o box_regex.o box_http.o box_map.o \
		box_product.o box_user.o \
		sql_connection.o sql_product.o sql_user.o)

.PHONY: all

all: $(TARGETDIR)/$(page).cgi $(BUILDDIR)/$(page).o $(OBJS) | $(HOMEDIR) $(TARGETDIR) $(CSSDEST) $(IMGDEST) $(HTMLDEST)

$(TARGETDIR)/$(page).cgi: $(BUILDDIR)/$(page).o $(OBJS) | $(HOMEDIR) $(TARGETDIR) $(CSSDEST) $(IMGDEST) $(HTMLDEST)
	gcc -g $(OUTPUT_OPTION) $^ `mysql_config --libs | awk '{print $$1,$$2;}'`

$(BUILDDIR)/%.o: %.c %.h | $(BUILDDIR)
	gcc -g -c `mysql_config --cflags` $(OUTPUT_OPTION) $<

$(BUILDDIR)/%.o: %.c | $(BUILDDIR)
	gcc -g -c $(OUTPUT_OPTION) $<

$(OBJS): | $(BUILDDIR)

$(CSSDEST): $(CSSSRC)
	rsync -rupE --delete $(CSSSRC) $(HOMEDIR)

$(IMGDEST): $(IMGSRC)
	rsync -rupE --delete $(IMGSRC) $(HOMEDIR) 

$(HTMLDEST): $(HTMLSRC)
	rsync -rupE --delete $(HTMLSRC) $(HOMEDIR)

$(BUILDDIR):
	mkdir $(BUILDDIR)

$(HOMEDIR):
	mkdir $(HOMEDIR)

$(TARGETDIR):
	mkdir $(TARGETDIR)
