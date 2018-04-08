#ifndef __XML_HEADER_H_INCLUDED__
#define __XML_HEADER_H_INCLUDED__

#include <stdio.h>
#include <stdlib.h> 
#include <libxml/parser.h>
#include <libxml/tree.h>


xmlDocPtr createDocument()
{
   xmlDocPtr document;
   document = xmlNewDoc((const xmlChar*)"1.0"); // XML version


   return document;
}

void parseDocument(){

	xmlDocPtr doc;
	xmlNodePtr cur;
	doc = xmlParseFile("tourists.xml");
	if (doc == NULL ) {
		fprintf(stderr,"Document not parsed successfully. \n");
	return;
	}
	cur = xmlDocGetRootElement(doc);
	if (cur == NULL) {
		fprintf(stderr,"empty document\n");
		xmlFreeDoc(doc);
	return;
	}
	if (xmlStrcmp(cur->name, (const xmlChar *) "story")) {
		fprintf(stderr,"document of the wrong type, root node != story"
		xmlFreeDoc(doc);
	return;
	}

}

addNewTravel();
