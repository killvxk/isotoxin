#include "stdafx.h"
#pragma warning (disable:4324)
#include "sodium.h"


static size_t header_callback(char *buffer, size_t size, size_t nitems, void *userdata)
{
    return size * nitems;
}

static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    ts::buf_c *resultad = (ts::buf_c *)userdata;
    resultad->append_buf(ptr, size * nmemb);
    return size * nmemb;
}

int proc_upd(const ts::wstrings_c & pars)
{
    int autoupdate_proxy = 0;
    ts::str_c address( "https://github.com/Rotkaermota/Isotoxin/releases/download/0.2.371/isotoxin.0.2.371.zip" );
    ts::str_c proxy( "srv:9050" );

    CURL *curl = curl_easy_init();
    ts::buf_c d;
    int rslt = 0;
    rslt = curl_easy_setopt(curl, CURLOPT_WRITEDATA, &d);
    rslt = curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, header_callback);
    rslt = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    rslt = curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);

    rslt = curl_easy_setopt(curl, CURLOPT_PROXY, nullptr);
    rslt = curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50);
    rslt = curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1);
    rslt = curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl");
    
    rslt = curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_HEADER, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_PROXY, nullptr);
    rslt = curl_easy_setopt(curl, CURLOPT_PROXYUSERPWD, nullptr);
    rslt = curl_easy_setopt(curl, CURLOPT_USERPWD, nullptr);
    rslt = curl_easy_setopt(curl, CURLOPT_KEYPASSWD, nullptr);
    rslt = curl_easy_setopt(curl, CURLOPT_RANGE, nullptr);
    rslt = curl_easy_setopt(curl, CURLOPT_HTTPPROXYTUNNEL, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_NOPROXY, nullptr);
    rslt = curl_easy_setopt(curl, CURLOPT_FAILONERROR, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_UPLOAD, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_DIRLISTONLY, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_APPEND, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_NETRC, CURL_NETRC_IGNORED);
    rslt = curl_easy_setopt(curl, CURLOPT_TRANSFERTEXT, 0);

    char errorbuffer[CURL_ERROR_SIZE];
    rslt = curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorbuffer);
    rslt = curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, 0ull);
    rslt = curl_easy_setopt(curl, CURLOPT_UNRESTRICTED_AUTH, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_REFERER, nullptr);
    rslt = curl_easy_setopt(curl, CURLOPT_AUTOREFERER, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, nullptr);
    rslt = curl_easy_setopt(curl, CURLOPT_POSTREDIR, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_FTPPORT, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_LOW_SPEED_LIMIT, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_LOW_SPEED_TIME, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_MAX_SEND_SPEED_LARGE, 0ull);
    rslt = curl_easy_setopt(curl, CURLOPT_MAX_RECV_SPEED_LARGE, 0ull);
    rslt = curl_easy_setopt(curl, CURLOPT_RESUME_FROM_LARGE, 0ull);
    rslt = curl_easy_setopt(curl, CURLOPT_SSLCERT, nullptr);
    rslt = curl_easy_setopt(curl, CURLOPT_SSLCERTTYPE, nullptr);
    rslt = curl_easy_setopt(curl, CURLOPT_SSLKEY, nullptr);
    rslt = curl_easy_setopt(curl, CURLOPT_SSLKEYTYPE, nullptr);
    rslt = curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_SSLVERSION, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_CRLF, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_QUOTE, nullptr);
    rslt = curl_easy_setopt(curl, CURLOPT_POSTQUOTE, nullptr);
    rslt = curl_easy_setopt(curl, CURLOPT_PREQUOTE, nullptr);
    rslt = curl_easy_setopt(curl, CURLOPT_COOKIESESSION, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_TIMECONDITION, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_TIMEVALUE, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, nullptr);
    rslt = curl_easy_setopt(curl, CURLOPT_STDERR, stdout);
    rslt = curl_easy_setopt(curl, CURLOPT_INTERFACE, nullptr);
    rslt = curl_easy_setopt(curl, CURLOPT_KRBLEVEL, nullptr);
    rslt = curl_easy_setopt(curl, CURLOPT_TELNETOPTIONS, nullptr);
    rslt = curl_easy_setopt(curl, CURLOPT_RANDOM_FILE, nullptr);
    rslt = curl_easy_setopt(curl, CURLOPT_EGDSOCKET, nullptr);
    rslt = curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT_MS, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_FTP_CREATE_MISSING_DIRS, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_WHATEVER);
    rslt = curl_easy_setopt(curl, CURLOPT_FTP_ACCOUNT, nullptr);
    rslt = curl_easy_setopt(curl, CURLOPT_IGNORE_CONTENT_LENGTH, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_FTP_SKIP_PASV_IP, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_FTP_FILEMETHOD, 0);
    rslt = curl_easy_setopt(curl, CURLOPT_FTP_ALTERNATIVE_TO_USER, nullptr);

    if (autoupdate_proxy > 0)
    {
        ts::token<char> t( proxy, ':' );
        ts::str_c proxya = *t;
        ++t;
        ts::str_c proxyp = *t;

        int pt = 0;
        if (autoupdate_proxy == 1) pt = CURLPROXY_HTTP;
        else if (autoupdate_proxy == 2) pt = CURLPROXY_SOCKS4;
        else if (autoupdate_proxy == 3) pt = CURLPROXY_SOCKS5_HOSTNAME;

        rslt = curl_easy_setopt(curl, CURLOPT_PROXY, proxya.cstr());
        rslt = curl_easy_setopt(curl, CURLOPT_PROXYPORT, proxyp.as_int());
        rslt = curl_easy_setopt(curl, CURLOPT_PROXYTYPE, pt);
    }

    
    rslt = curl_easy_setopt(curl, CURLOPT_URL, address.cstr());
    rslt = curl_easy_perform(curl);

    if (curl) curl_easy_cleanup(curl);

    d.save_to_file(L"isotoxin.0.2.371.zip");

    return 0;
}

int proc_sign(const ts::wstrings_c & pars)
{
    if (pars.size() < 3) return 0;

    ts::wstr_c arch = pars.get(1); ts::fix_path( arch, FNO_SIMPLIFY );
    ts::wstr_c proc = pars.get(2); ts::fix_path( proc, FNO_SIMPLIFY );

    if (!is_file_exists(arch.as_sptr()))
    {
        Print(FOREGROUND_RED, "arch file not found: %s\n", to_str(arch).cstr()); return 0;
    }
    if (!is_file_exists(proc.as_sptr()))
    {
        Print(FOREGROUND_RED, "proc file not found: %s\n", to_str(proc).cstr()); return 0;
    }
    ts::buf_c b; b.load_from_disk_file(arch);
    ts::aint archlen = b.size();
    ts::md5_c md5;
    md5.update(b.data(), b.size()); md5.done();
    ts::abp_c bp;
    b.load_from_disk_file(proc);
    bp.load(b.cstr());

    ts::wstr_c procpath = ts::fn_get_path(proc);
    auto pa = [&]( ts::asptr p ) ->ts::wstr_c
    {
        return ts::fn_join(procpath, to_wstr(bp.get_string(p)));
    };

    b.load_from_disk_file( pa(CONSTASTR("ver")) );
    ts::str_c ver = b.cstr();
    ver.replace_all('/','.').trim();

    ts::str_c ss(CONSTASTR("ver="));
    ss.append( ver );
    ss.append(CONSTASTR("\r\nurl="));

    ts::str_c path = bp.get_string(CONSTASTR("path"));
    path.replace_all(CONSTASTR("%ver%"), ver);
    path.replace_all(CONSTASTR("%https%"), CONSTASTR("https://"));
    path.replace_all(CONSTASTR("%http%"), CONSTASTR("http://"));
    path.appendcvt(ts::fn_get_name_with_ext(arch));


    ss.append(path);

    ss.append(CONSTASTR("\r\nsize="));
    ss.append_as_num(archlen);
    ss.append(CONSTASTR("\r\nmd5="));
    ss.append_as_hex(md5.result(), 16);

    unsigned char pk[crypto_sign_PUBLICKEYBYTES];
    unsigned char sk[crypto_sign_SECRETKEYBYTES];
    b.clear();
    b.load_from_disk_file( pa(CONSTASTR("sk")) );
    if (b.size() != crypto_sign_SECRETKEYBYTES)
    {
        rebuild:
        crypto_sign_keypair(pk, sk);

        FILE *f = _wfopen(pa(CONSTASTR("sk")), L"wb");
        fwrite(sk, 1, sizeof(sk), f);
        fclose(f);

        ts::str_c spk;
        for(int i=0;i<crypto_sign_PUBLICKEYBYTES;++i)
            spk.append(CONSTASTR("0x")).append_as_hex(pk[i]).append(CONSTASTR(", "));
        spk.trunc_length(2);

        f = _wfopen(pa(CONSTASTR("pk")), L"wb");
        fwrite(spk.cstr(), 1, spk.get_length(), f);
        fclose(f);
    } else
    {
        memcpy(sk, b.data(), crypto_sign_SECRETKEYBYTES);
        crypto_sign_ed25519_sk_to_pk(pk, sk);

        b.load_from_disk_file( pa(CONSTASTR("pk")) );
        ts::token<char> t(b.cstr(), ',');
        int n = 0;
        for(;t; ++t, ++n)
        {
            if (n >= sizeof(pk)) goto rebuild;
            ts::str_c nx(*t);
            nx.trim();
            if (pk[n] != (byte)nx.as_uint())
                goto rebuild;
        }
        if (n < sizeof(pk)) goto rebuild;
    }

    unsigned char sig[crypto_sign_BYTES];
    unsigned long long siglen;
    crypto_sign_detached(sig,&siglen, (const byte *)ss.cstr(), ss.get_length(), sk);

    ss.append(CONSTASTR("\r\nsign="));
    ss.append_as_hex(sig, (int)siglen);

    if (CONSTASTR("github") == bp.get_string(CONSTASTR("wiki")))
    {
        ss.insert(0,CONSTASTR("[begin]\r\n"));
        ss.replace_all(CONSTASTR("\r\n"), CONSTASTR("`<br>\r\n`"));
        ss.replace_all(CONSTASTR("[begin]`"), CONSTASTR("[begin]"));
        ss.append(CONSTASTR("`<br>\r\n[end]<br>\r\n"));
    }

    FILE *f = _wfopen(pa(CONSTASTR("result")), L"wb");
    fwrite(ss.cstr(), 1, ss.get_length(), f);
    fclose(f);


    return 0;
}
