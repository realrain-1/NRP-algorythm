#include <stdio.h>
#include <string.h>

    char str[200];
    char * phrase1[20];
    char * phraseType1[20];
    char * phrase2[20];
    char * phraseType2[20];
    char * tence;
    char * noun[7] = {(char *)"sk", (char *)"rm", (char *)"rmsu", (char *)"rmrjt", (char *)"rhdiddl", (char *)"qkq", (char *)"rhd"};

int IsNoun(char * str) 
{
    int isNoun = 0;
    int len = 7;
    for(int i=0;i < len;i++) 
    {
        if(strcmp(str, noun[i]) == 0) isNoun = 1;
    }

    return isNoun;
}


int main() {
    char * token;
    char endingMark;
    char * sentenceType;
    char * relativeElevation;
    char * subjectElevation = (char *)"no";

    int len;
    int phraseNum = 0;

    gets(str);

    len = strlen(str);
    endingMark = str[len-1];

    // 문장부호 분석
    if(endingMark == '.') sentenceType = (char *)"undefined";
    else if(endingMark == '?') sentenceType = (char *)"question";
    else if(endingMark == '!') sentenceType = (char *)"exclamation";

    // 어절단위 쪼개기
    // 1st token
    token = strtok(str, " ");
    phrase1[phraseNum] = token;
    phraseNum++;

    // other tokens
    while(token != NULL) {
        token = strtok(NULL, " ");
        phrase1[phraseNum] = token;
        phraseNum++;
    }
    phraseNum--;

    // 종결어미 분석

    char * lastPhrase = phrase1[phraseNum - 1];
phraseType1[phraseNum - 1] = (char *)"explanation";
    char * checkPhrase = lastPhrase + strlen(lastPhrase);

    if(strcmp(sentenceType, "undefined") == 0) {

            // 하십시오체
            // 평서문, (스)ㅂ니다. 확인

            if(strcmp(checkPhrase - 8, "tmqslek.") == 0) 
            {
                sentenceType = (char *)"statement";
                relativeElevation = (char *)"hashipsio";
                checkPhrase -= 8;
            }

            else if(strcmp(checkPhrase - 6, "qslek.") == 0) 
            {
                sentenceType = (char *)"statement";
                relativeElevation = (char *)"hashipsio";
                checkPhrase -= 6;
            }

    
            // 청유문, (으)시지요. 확인

            else if(strcmp(checkPhrase -9, "dmtlwldy.") == 0)
            {
                sentenceType = (char *)"chungyoumoon";
                relativeElevation = (char *)"hashipsio";
                checkPhrase -= 9;
            }

            else if(strcmp(checkPhrase -7, "tlwldy.") == 0)
            {
                sentenceType = (char *)"chungyoumoon";
                relativeElevation = (char *)"hashipsio";
                checkPhrase -= 7;
            }

            // 명령문, (으)십시오. 확인

            else if(strcmp(checkPhrase - 10, "dmtlqtldh.") == 0)
            {
                sentenceType = (char *)"command";
                relativeElevation = (char *)"hashipsio";
                checkPhrase -= 10;

            }

            else if(strcmp(checkPhrase - 8, "tlqtldh.") == 0)
            {
                sentenceType = (char *)"command";
                relativeElevation = (char *)"hashipsio";
                checkPhrase -= 8;

            }

            // 하오체
            // 평서문 또는 명령문, (으)오 확인

            else if(strcmp(checkPhrase - 5, "dmdh.") == 0)
            {
                sentenceType = (char *)"statement or command";
                relativeElevation = (char *)"hao";
                checkPhrase -= 5;
            }

            else if(strcmp(checkPhrase - 3, "dh.") == 0 && strcmp(checkPhrase - 8, "tlqtldh.") != 0)
            {
                sentenceType = (char *)"statement or command";
                relativeElevation = (char *)"hao";
                checkPhrase -= 3;
            }

            // 청유문, 읍시다 확인

            else if(strcmp(checkPhrase - 7, "mqtlek.") == 0)
            {
                sentenceType = (char *)"chungyoumoon";
                relativeElevation = (char *)"hao";
                checkPhrase -= 7;

            }
            
            // 하게체
            // 평서문, 네 확인

            else if(strcmp(checkPhrase - 3, "sp.") == 0)
            {
                sentenceType = (char *)"statement";
                relativeElevation = (char *)"hagae";
                checkPhrase -= 3;

            }
                        
            // 청유문, (으)세 확인

            else if(strcmp(checkPhrase - 5, "dmtp.") == 0)
            {
                sentenceType = (char *)"chungyoumoon";
                relativeElevation = (char *)"hagae";
                checkPhrase -= 5;

            }

            else if(strcmp(checkPhrase - 3, "tp.") == 0)
            {
                sentenceType = (char *)"chungyoumoon";
                relativeElevation = (char *)"hagae";
                checkPhrase -= 3;

            }

            // 명령문, 게 확인

            else if(strcmp(checkPhrase - 3, "rp.") == 0)
            {
                sentenceType = (char *)"command";
                relativeElevation = (char *)"hagae";
                checkPhrase -= 3;

            }
            
            // 해라체
            // 평서문, (이)다 확인

            else if(strcmp(checkPhrase - 5, "dlek.") == 0)
            {
                sentenceType = (char *)"statement";
                relativeElevation = (char *)"haera";
                checkPhrase -= 5;

            }

            else if(strcmp(checkPhrase - 3, "ek.") == 0)
            {
                sentenceType = (char *)"statement";
                relativeElevation = (char *)"haera";
                checkPhrase -= 3;

            }
                        
            // 청유문, 자 확인

            else if(strcmp(checkPhrase - 3, "wk.") == 0)
            {
                sentenceType = (char *)"chungyoumoon";
                relativeElevation = (char *)"haera";
                checkPhrase -= 3;

            }

            // 명령문, (어/아)라 확인

            else if(strcmp(checkPhrase - 5, "djfk.") == 0)
            {
                sentenceType = (char *)"command";
                relativeElevation = (char *)"haera";
                checkPhrase -= 5;

            }

            else if(strcmp(checkPhrase - 5, "dkfk.") == 0)
            {
                sentenceType = (char *)"command";
                relativeElevation = (char *)"haera";
                checkPhrase -= 5;

            }

            // 해요체
            // 평서문 또는 청유문 또는 명령문, (어/아)요 확인

            else if(strcmp(checkPhrase - 5, "djdy.") == 0)
            {
                sentenceType = (char *)"statement or chungyoumoon or command";
                relativeElevation = (char *)"haeyo";
                checkPhrase -= 5;

            }

            else if(strcmp(checkPhrase - 5, "dkdy.") == 0)
            {
                sentenceType = (char *)"statement or chungyoumoon or command";
                relativeElevation = (char *)"haeyo";
                checkPhrase -= 5;

            }

            // 해체
            // 평서문 또는 청유문 또는 명령문, 지, 어/아 확인

            else if(strcmp(checkPhrase - 3, "wl.") == 0)
            {
                sentenceType = (char *)"statement or chungyoumoon or command";
                relativeElevation = (char *)"hae";  
                checkPhrase -= 3;

            }     

            else if(strcmp(checkPhrase - 3, "dj.") == 0)
            {
                sentenceType = (char *)"statement or chungyoumoon or command";
                relativeElevation = (char *)"hae";  
                checkPhrase -= 3;

            }   

            else if(strcmp(checkPhrase - 3, "dk.") == 0)
            {
                sentenceType = (char *)"statement or chungyoumoon or command";
                relativeElevation = (char *)"hae";  
                checkPhrase -= 3;

            }    

    }
    else if(strcmp(sentenceType, "question") == 0) {

        // 하십시오체
        // (스)ㅂ니까. 확인
            if(strcmp(checkPhrase - 8, "tmqslRk?") == 0) 
            {
                relativeElevation = (char *)"hashipsio";
                checkPhrase -= 8;

            }

            else if(strcmp(checkPhrase - 6, "qslRk?") == 0) 
            {
                relativeElevation = (char *)"hashipsio";
                checkPhrase -= 6;

            }


            // 하오체
            // (으)오 확인

            else if(strcmp(checkPhrase - 5, "dmdh?") == 0)
            {
                relativeElevation = (char *)"hao";
                checkPhrase -= 5;

            }

            else if(strcmp(checkPhrase - 3, "dh?") == 0)
            {
                relativeElevation = (char *)"hao";
                checkPhrase -= 3;

            }
            
            // 하게체
            // 나 확인

            else if(strcmp(checkPhrase - 3, "sk?") == 0)
            {
                relativeElevation = (char *)"hagae";
                checkPhrase -= 3;

            }
            
            // 해라체
            // 니 확인

            else if(strcmp(checkPhrase - 3, "sl?") == 0)
            {
                relativeElevation = (char *)"haera";
                checkPhrase -= 3;

            }

            // 해요체
            //  (어/아)요 확인

            else if(strcmp(checkPhrase - 5, "djdy?") == 0)
            {
                relativeElevation = (char *)"haeyo";
                checkPhrase -= 5;

            }
            else if(strcmp(checkPhrase - 5, "dkdy?") == 0)
            {
                relativeElevation = (char *)"haeyo";
                checkPhrase -= 5;

            }

            // 해체
            // 지, 어/아, 나 확인

            else if(strcmp(checkPhrase - 3, "wl?") == 0)
            {
                relativeElevation = (char *)"hae";  
                checkPhrase -= 3;

            }

            else if(strcmp(checkPhrase - 3, "dj?") == 0)
            {
                relativeElevation = (char *)"hae";  
                checkPhrase -= 3;

            }

            else if(strcmp(checkPhrase - 3, "dk?") == 0)
            {
                relativeElevation = (char *)"hae";  
                checkPhrase -= 3;

            }

    }
    else if(strcmp(sentenceType, "exclamination") == 0) {

            // 하오체
            // 구려 확인

            if(strcmp(checkPhrase - 5, "rnfu!") == 0)
            {
                relativeElevation = (char *)"hao";
                checkPhrase -= 5;

            }
            
            // 하게체
            // 구면 확인

            else if(strcmp(checkPhrase - 6, "rnajs!") == 0)
            {
                relativeElevation = (char *)"hagae";
                checkPhrase -= 6;

            }
            
            // 해라체
            // 구나 확인

            else if(strcmp(checkPhrase - 5, "rnsk!") == 0)
            {
                relativeElevation = (char *)"haera";
                checkPhrase -= 5;

            }

            // 해요체
            // 군요 확인

            else if(strcmp(checkPhrase - 9, "rnsdy!") == 0)
            {
                relativeElevation = (char *)"haeyo";
                checkPhrase -= 9;

            }

            // 해체
            // 군, 어/아 확인

            else if(strcmp(checkPhrase - 5, "rns!") == 0)
            {
                relativeElevation = (char *)"haeyo";
                checkPhrase -= 5;

            }

            else
            {
                relativeElevation = (char *)"hae";  
                checkPhrase -= 3;
            }  

    }

    checkPhrase[0] = NULL;

    // 선어말어미 분석
    // 시제
    // 과거
    // 았/었 확인(더는 나중에...)

    if(strcmp(checkPhrase - 3, "djT") == 0 || strcmp(checkPhrase - 2, "dkT") == 0)
    {
        tence = (char *)"past";
        checkPhrase -= 3;
    }

    else if(strcmp(checkPhrase - 2, "jT") == 0 || strcmp(checkPhrase - 2, "kT") == 0)
    {
        tence = (char *)"past";
        checkPhrase -= 2;
    }

    else if(strcmp(checkPhrase - 3, "tuT") == 0)
    {
        tence = (char *)"past";
        subjectElevation = (char *)"yes";
        checkPhrase -= 3;
    }

    else if(strcmp(checkPhrase - 3, "duT") == 0)
    {
        tence = (char *)"past";
        checkPhrase -= 3;
    }

    // 미래
    // 겠 확인(ㄹ 것이다는 나중에...)
    else if(strcmp(checkPhrase - 3, "rpT") == 0)
    {
        tence = (char *)"future";
        checkPhrase -= 3;
    }

    // 현재
    // 나머지(동사는 -ㄴ-/는, 형용사나 '-이다'는 없다.)
    else if(strcmp(checkPhrase - 3, "sms") == 0)
    {
        tence = (char *)"present";
        checkPhrase -= 3;
    }
    else if(strcmp(checkPhrase - 1, "s") == 0)
    {
        tence = (char *)"present";
        checkPhrase -= 1;
    }
    else 
    {
        tence = (char *)"present";
    }
    
    checkPhrase[0] = NULL;
    // printf("%s\n", lastPhrase);

    // 문장성분 분석
    // 서술어가 되다/아니다 일 때(보어 존재)
       for(int i = phraseNum - 2;i >= 0;i--) 
        {
            int phrase1Length = strlen(phrase1[i]);

            checkPhrase = phrase1[i] + phrase1Length;

            if(strcmp(lastPhrase, "ehl") == 0 || strcmp(lastPhrase, "dksl") == 0)
            {
                
                if(strcmp(checkPhrase - 2, "dl") == 0 || strcmp(checkPhrase - 2, "rk") == 0) 
                {
                    // 주어
                    if(i != phraseNum - 2)phraseType1[i] = (char *)"subject";

                    // 보어
                    else phraseType1[i] = (char *)"complement";
                    
                }


            }

            // 서술어가 되다/아니다 가 아닐때(보어 x)
            else
            {
                if(strcmp(checkPhrase - 2, "dl") == 0 || strcmp(checkPhrase - 2, "rk") == 0)phraseType1[i] = (char *)"subject";

            }

            // 목적어
            if(strcmp(checkPhrase - 2, "mf") ==0 || strcmp(checkPhrase - 3, "fmf") == 0)phraseType1[i] = (char *)"object";

            // 관형어
            // 관형사
            else if(strcmp(phrase1[i], "to") == 0 || strcmp(phrase1[i], "dl") == 0)phraseType1[i] = (char *)"gwanhyoungo";

            // 체언 + 관형격조사 의
            else if(strcmp(checkPhrase - 3, "dml") == 0)phraseType1[i] = (char *)"gwanhyoungo";

            // 용언 + 과거 관형사형 전성 어미 '던'
            else if(strcmp(checkPhrase - 3, "ejs") == 0)phraseType1[i] = (char *)"gwanhyoungo";

            // 용언/서술격 조사 '이다' + 과거 관형사형 전성 어미 'ㄴ'
            else if(strcmp(checkPhrase - 1, "s") == 0 && strcmp(checkPhrase - 3, "dms") != 0 && strcmp(checkPhrase - 3, "sms") != 0)phraseType1[i] = (char *)"gwanhyoungo";
            
            // 은, 는 의 처리
            // 동사 + 과거 관형사형 전성 어미 '은'  /  형용사 + 현재 관형사형 전성 어미 '은'
            else if(strcmp(checkPhrase - 3, "dms") == 0) 
            {
                char * checkWord = phrase1[i];
                int target = strlen(checkWord) - 3;
                checkWord[target] = NULL;

                if(IsNoun(checkWord) == 0)
                {
                    if(strcmp(tence, "past") == 0)
                    {
                    phraseType1[i] = (char *)"gwanhyoungo(verb)";
                    }
                    else phraseType1[i] = (char *)"gwanhyoungo(adjective)";
                }

                else phraseType1[i] = (char *)"subject or object";
                
            }

            // 동사 + 현재 관형사형 전성 어미 '는'
            else if(strcmp(checkPhrase - 3, "sms") == 0) 
            {
                char * checkWord = phrase1[i];
                int target = strlen(checkWord) - 3;
                checkWord[target] = NULL;

                if(IsNoun(checkWord) == 0)
                {
                phraseType1[i] = (char *)"gwanhyoungo(verb)";
                }
                else phraseType1[i] = (char *)"subject or object";
                
            }    

            // 부사어
            // 성분 부사어
            // 부사
            else if(strcmp(phrase1[i], "Qkffl") == 0 || strcmp(phrase1[i], "aodn") == 0)phraseType1[i] = (char *)"adverb";

            // 체언 + 에/에게/에서
            else if(strcmp(checkPhrase - 2, "dp") == 0 || strcmp(checkPhrase - 4, "dprp") == 0 || strcmp(checkPhrase - 4, "dptj") == 0)phraseType1[i] = (char *)"adverb";

            // 체언 + (으)로
            else if(strcmp(checkPhrase - 2, "fh") == 0)phraseType1[i] = (char *)"adverb";

            // 와/과 처리
            // 체언 + 와/과
            else if(strcmp(checkPhrase - 3, "dhk") == 0 || strcmp(checkPhrase - 3, "rhk") == 0)
            {
                if(strcmp(phraseType1[i+1], "subject") == 0 || strcmp(phraseType1[i+1], "object") == 0)phraseType1[i] = (char *)"subject";
                else phraseType1[i] = (char *)"adverb";
            }

            // 이 처리(부사어인 것만 덮어쓰기)
            // 용언 + 이
            else if(strcmp(checkPhrase - 2, "dl") == 0)
            {
                char * checkWord = phrase1[i];
                int target = strlen(checkWord) - 2;
                checkWord[target] = NULL;

                if(IsNoun(checkWord) == 0)phraseType1[i] = (char *)"adverb";
                
            }

            // 용언 + 게/도록
            else if(strcmp(checkPhrase - 2, "rp") == 0 || strcmp(checkPhrase - 5, "ehfhr") == 0)phraseType1[i] = (char *)"adverb"; 
        }

        int subjectCount = 0;

        for(int i = 0;i < phraseNum - 1;i++) 
        {
            
            if(strcmp(phraseType1[i], "subject or object") == 0) 
            {
                if(subjectCount == 0) 
                {
                phraseType1[i] = (char *)"subject";
                    subjectCount++;
                }
                else phraseType1[i] = (char *)"object";
            }

        }

    // check
    printf("sentence type:%s\nrelative elevation:%s\ntence:%s\nsubject elevation:%s\n", sentenceType, relativeElevation, tence, subjectElevation);

    for(int i=0;i<phraseNum;i++) printf("%s:%s ", phrase1[i],phraseType1[i]);
}

