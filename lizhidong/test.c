linkList reverse(linkList head) {
	linkList p,q,pr;
	    p = head->next;
		  q = NULL;
		    head->next = NULL;
			  while(p) {

				      pr = p->next;
					      p->next = q;
						      q = p;
							      p = pr;
								    } 
			    head->next = q;
				  return head;
} 
